#ifndef PAUSE_H
#define PAUSE_H

#include <ncurses.h>
#include "utilities.hpp"

class Pause {
private:
    WINDOW *menu;

    void render();
    int interact();

public:
    Pause();
    void run();
};

#endif // PAUSE_H