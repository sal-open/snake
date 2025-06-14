#include "pause.hpp"

Pause::Pause() {    
}

void Pause::render(int selected) {
    mvwprintw(menu, 1, (WIDTH_P - (int)strlen(menu_header)) / 2, "%s", menu_header);

    for (int i = 0; i < PAUSE_MENU; i++) {
        if (i == selected) wattron(menu, A_REVERSE);

        if (i < 5) {
            mvwprintw(menu, HEIGHT_P / 3, WIDTH_P / 5 + i * 3,
                      "%s", items[i]);
        }
        else if (i < 10) {
            mvwprintw(menu, HEIGHT_P / 3 + 2, WIDTH_P / 5 + (i % 5) * 3,
                      "%s", items[i]);
        }
        else {
            mvwprintw(menu, HEIGHT_P - 2, (WIDTH_P - (int)strlen(items[i])) / 2,
                      "%s", items[i]);
        }
        wattroff(menu, A_REVERSE);
    }
}

int Pause::interact() {
    int selected = 0;

    keypad(menu, TRUE);

    while (true) {
    render(selected);

    int ch = wgetch(menu);

    switch (ch) {
    case KEY_RIGHT:
      selected = (selected + 1) % PAUSE_MENU;
      break;

    case KEY_LEFT:
      selected = (selected - 1 + PAUSE_MENU) % PAUSE_MENU;
      break;

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
    
    case '\n':
      return selected;
    }
  }
}

int Pause::run() {
    menu = interface(HEIGHT_P, WIDTH_P);

    int selected = 0;
    
    selected = interact();

    return selected;
}