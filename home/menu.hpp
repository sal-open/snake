#ifndef MENU_HPP
#define MENU_HPP

#include <cstring>
#include <ncurses.h>
#include "info.hpp"
#include "utilities.hpp"

class Menu {
private:
    Info info;

    const char* items[MENU] = { "Nuova partita", "Punteggi", "Informazioni", "Esci" };
    const char  triggers[MENU] = { 'n', 'p', 'i', 'e' };

    void renderMenu(WINDOW* win, const char* title, int selected);
    int interactMenu(WINDOW* win);

public:
    Menu();
    
    void init();
    void run();
};

#endif // MENU_HPP