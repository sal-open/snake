#include "menu.hpp"
#include "game/game.hpp"
#include "info.hpp"
#include "score/data.hpp"
#include "game/snake.hpp"

Menu::Menu() {
}

void Menu::init() {
  initscr();
  curs_set(0);
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
  start_color();
  use_default_colors();
  refresh();
}

void Menu::renderMenu(int selected) {

  mvwprintw(menu, 1, (WIDTH_M - (int)strlen(title)) / 2, "%s", title);

  for (int i = 0; i < MENU; i++) {
    const char *text = items[i];
    
    int y = HEIGHT_M / 3 + i * 2;
    int x = (WIDTH_M - (int)strlen(text)) / 2;

    if (i == selected) {
      wattron(menu, A_REVERSE);
      mvwprintw(menu, y, x, "%s", text);
      wattroff(menu, A_REVERSE);
    }
    else mvwprintw(menu, y, x, "%s", text);
  }
  wrefresh(menu);
}

int Menu::interactMenu(WINDOW *menu) {
  int selected = 0;

  keypad(menu, TRUE);

  while (true) {
    renderMenu(selected);

    int ch = wgetch(menu);

    switch (ch) {
    case KEY_UP:
      selected = (selected - 1 + MENU) % MENU;
      break;

    case KEY_DOWN:
      selected = (selected + 1) % MENU;
      break;

    case '\n':
      return selected;

    default:
      for (int i = 0; i < MENU; i++) {
        if (ch == triggers[i])
          return i;
      }
      break;
    }
  }
}

void Menu::run() {
  menu = interface(HEIGHT_M, WIDTH_M);

  box(menu, 0, 0);

  while (true) {
    switch (interactMenu(menu)) {
    case 0: {
      game.play();

      box(menu, 0, 0);
      wrefresh(menu);
      break;
    }

    case 1: {
      Data::mostraPunteggiNcurses(); // mantiene ncurses attivo
      clear();
      refresh();
      box(menu, 0, 0);
      wrefresh(menu);
      keypad(menu, true);
      break;
    }

    case 2: {
      info.showInfo();
      box(menu, 0, 0);
      break;
    }

    case 3: {
      end();
      break;
    }
    }
  }
}
