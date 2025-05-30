#ifndef MENU_HPP
#define MENU_HPP

#include <cstring>
#include <ncurses.h>
#include "../utilities.hpp"

class Screen;

class Menu {
private:
    Screen &terminal;
    const char* items[MENU] = { "Nuova partita", "Punteggi", "Informazioni", "Esci" };
    const char  triggers[MENU] = { 'n', 'p', 'i', 'e' };

    void renderMenu(WINDOW* win, const char* title, int selected);
    int interactMenu(WINDOW* win);

public:
    Menu(Screen &s);

    void run();
};

#endif // MENU_HPP