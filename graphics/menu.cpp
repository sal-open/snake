#include "menu.hpp"
#include "screen.hpp"

Menu::Menu(Screen &s): terminal(s) {
}

void Menu::renderMenu(WINDOW* win, const char* title, int selected) {

    int width = getmaxx(win);
    mvwprintw(win, 1, (width - (int)strlen(title)) / 2, "%s", title);
    for (int i = 0; i < MENU; ++i) {
        const char* text = this->items[i];
        int y = getmaxy(win)/3 + i * 2;
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

int Menu::interactMenu(WINDOW* win) {
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
                    if (ch == triggers[i]) return i;
                }
                break;
        }
    }
}

void menuRedirect(int selection) {
    
}

void Menu::run() {
    WINDOW *win = terminal.interface('m');

    interactMenu(win);
}
