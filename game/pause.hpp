#ifndef PAUSE_H
#define PAUSE_H

#include <cstring>
#include <ncurses.h>
#include "utilities.hpp"
#include "levels/levels.hpp"

class Pause {
private:
    WINDOW *menu;
    const char *menu_header = " PARTITA IN PAUSA";
    const char* items[11] = { "1", "2", "3", "4", "5",
                              "6", "7", "8", "9", "10",
                              "Termina partita" };
    Levels levels;

    void render(int selected);
    int interact();

public:
    Pause();
    int run();
};

#endif // PAUSE_H