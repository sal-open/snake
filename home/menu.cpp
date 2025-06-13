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

void Menu::renderMenu(WINDOW *win, const char *title, int selected) {

  int width = getmaxx(win);
  mvwprintw(win, 1, (width - (int)strlen(title)) / 2, "%s", title);
  for (int i = 0; i < MENU; ++i) {
    const char *text = this->items[i];
    int y = getmaxy(win) / 3 + i * 2;
    int x = (width - (int)strlen(text)) / 2;
    if (i == selected) {
      wattron(win, A_REVERSE);
      mvwprintw(win, y, x, "%s", text);
      wattroff(win, A_REVERSE);
    } else {
      mvwprintw(win, y, x, "%s", text);
    }
  }
  wrefresh(win);
}

int Menu::interactMenu(WINDOW *win) {
  int selected = 0;
  char title[] = "MENU";

  keypad(win, TRUE);

  while (true) {
    renderMenu(win, title, selected);

    int ch = wgetch(win);

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
  WINDOW *menu = interface(HEIGHT_M, WIDTH_M);

  box(menu, 0, 0);

  while (true) {
    switch (interactMenu(menu)) {
    case 0: {
      game.startGame();

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
