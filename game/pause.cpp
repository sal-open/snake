#include "pause.hpp"

Pause::Pause() {}

void Pause::render(int selected) {
  mvwprintw(menu, 1, (WIDTH_P - (int)strlen(menu_header)) / 2, "%s",
            menu_header);

  // Ottengo la lista dei livelli completati
  int *livelliCompletati = levels.getLivelliCompletati();
  if (!livelliCompletati) {
    return; // Gestione dell'errore
  }

  init_pair(
      4, COLOR_GREEN,
      -1); // Definisco una nuova coppia di colori per i livelli completati

  for (int i = 0; i < PAUSE_MENU; i++) {
    bool isCompletato = false;
    for (int j = 0; livelliCompletati[j] != -1; j++) {
      if (livelliCompletati[j] == i) {
        isCompletato = true;
        break;
      }
    }

    if (i == selected && !isCompletato) {
      wattron(menu, A_REVERSE);
    }

    if (isCompletato) {
      wattron(menu, COLOR_PAIR(4));
    }

    if (i < 5) {
      mvwprintw(menu, HEIGHT_P / 3, WIDTH_P / 5 + i * 3, "%s", items[i]);
    } else if (i < 10) {
      mvwprintw(menu, HEIGHT_P / 3 + 2, WIDTH_P / 5 + (i % 5) * 3, "%s",
                items[i]);
    } else {
      mvwprintw(menu, HEIGHT_P - 2, (WIDTH_P - (int)strlen(items[i])) / 2, "%s",
                items[i]);
    }

    wattroff(menu, A_REVERSE);
    wattroff(menu, COLOR_PAIR(4));
  }

  // Aggiungo il messaggio per uscire
  mvwprintw(menu, HEIGHT_P - 3, (WIDTH_P - 30) / 2,
            "Premi 'e' per tornare alla partita");

  delete[] livelliCompletati;
}

int Pause::interact() {
  int selected = 0;
  int *livelliCompletati = levels.getLivelliCompletati();
  if (!livelliCompletati) {
    return 10; // In caso di errore, termina la partita
  }

  keypad(menu, TRUE);

  while (true) {
    render(selected);

    int ch = wgetch(menu);

    switch (ch) {
    case 'e':
      wclear(menu);
      wrefresh(menu);
      delwin(menu);
      return -1;

    case KEY_RIGHT: {
      int nextSelected = (selected + 1) % PAUSE_MENU;
      // Salta i livelli completati
      while (nextSelected <
             10) { // Solo per i livelli, non per "Termina partita"
        bool isCompletato = false;
        for (int i = 0; livelliCompletati[i] != -1; i++) {
          if (livelliCompletati[i] == nextSelected) {
            isCompletato = true;
            break;
          }
        }
        if (!isCompletato)
          break;
        nextSelected = (nextSelected + 1) % PAUSE_MENU;
      }
      selected = nextSelected;
      break;
    }

    case KEY_LEFT: {
      int prevSelected = (selected - 1 + PAUSE_MENU) % PAUSE_MENU;
      // Salta i livelli completati
      while (prevSelected <
             10) { // Solo per i livelli, non per "Termina partita"
        bool isCompletato = false;
        for (int i = 0; livelliCompletati[i] != -1; i++) {
          if (livelliCompletati[i] == prevSelected) {
            isCompletato = true;
            break;
          }
        }
        if (!isCompletato)
          break;
        prevSelected = (prevSelected - 1 + PAUSE_MENU) % PAUSE_MENU;
      }
      selected = prevSelected;
      break;
    }

    case KEY_UP:
      if (selected < 5) {
        selected = 10;
        break;
      }
      if (selected == 10) {
        selected = 7;
        break;
      }
      selected = (selected - 5 + PAUSE_MENU) % PAUSE_MENU;
      break;

    case KEY_DOWN:
      if (selected > 5 && selected < 10) {
        selected = 10;
        break;
      }
      if (selected == 10) {
        selected = 2;
        break;
      }
      selected = (selected + 5) % PAUSE_MENU;
      break;

    case '\n': {
      // Verifica se il livello selezionato è completato
      bool isCompletato = false;
      for (int i = 0; livelliCompletati[i] != -1; i++) {
        if (livelliCompletati[i] == selected) {
          isCompletato = true;
          break;
        }
      }
      // Se non è completato o è "Termina partita", procedi
      if (!isCompletato || selected == 10) {
        delete[] livelliCompletati;
        return selected;
      }
      break;
    }
    }
  }
}

int Pause::run() {
  menu = interface(HEIGHT_P, WIDTH_P);

  int selected = 0;

  selected = interact();

  return selected;
}