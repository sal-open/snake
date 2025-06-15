#ifndef MENU_H
#define MENU_H

#include <cstring>
#include <ncurses.h>
#include "game/game.hpp"
#include "info.hpp"
#include "utilities.hpp"
#include "score/data.hpp"

class Menu {
private:
    Info info;
    Game game;
    Data user;    

    WINDOW *menu;

    const char *title = "MENU";
    const char* items[MENU] = { "Nuova partita", "Punteggi", "Informazioni", "Esci" };
    const char  triggers[MENU] = { 'n', 'p', 'i', 'e' };

    void renderMenu(int selected);
    int interactMenu(WINDOW* win);

public:
    Menu();
    
    void init();
    void run();
};

#endif // MENU_H