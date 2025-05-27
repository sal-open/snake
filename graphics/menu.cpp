#include "menu.hpp"
#include <cstring>

const char* Menu::items[]    = { "Nuova partita", "Punteggi", "Esci" };
const char  Menu::triggers[] = { 'n', 'p', 'e' };
const int   Menu::count      = sizeof(Menu::items) / sizeof(Menu::items[0]);

Menu::Menu(const char* title): title(title) {}

void Menu::renderMenu(WINDOW* win, const char* title, int selected) {
    werase(win);
    box(win, 0, 0);
    
    int width = getmaxx(win);
    mvwprintw(win, 1, (width - (int)strlen(title)) / 2, "%s", title);
    for (int i = 0; i < count; ++i) {
        const char* text = items[i];
        int y = 3 + i * 2;
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

int Menu::interactMenu(WINDOW* win, const char* title) {
    int selected = 0;

    while (true) {
        renderMenu(win, title, selected);

        int ch = wgetch(win);

        switch (ch) {
            case KEY_UP:
                selected = (selected - 1 + count) % count;
                break;
            case KEY_DOWN:
                selected = (selected + 1) % count;
                break;
            case '\n':
                return selected;
            default:
                for (int i = 0; i < count; ++i) {
                    if (ch == triggers[i]) {
                        return i;
                    }
                }
                break;
        }
    }
}

int Menu::run() {

    WINDOW * win = newwin(HEIGHT, WIDTH, offset.y, offset.x);

    int choice = interactMenu(win, title);

    return choice;
}
