#ifndef APPLE_H
#define APPLE_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ncurses.h>
#include "utilities.hpp"

// Limiti finestra di gioco
#define MIN_X 2
#define MAX_X (WIDTH_G - 2)
#define MIN_Y 2
#define MAX_Y (HEIGHT_G - 2)

struct apple {
    pair coord;
};

class Apple {
private:
    apple apples;
    
public:
    Apple();

    void createApple();
    pair getPosition() const;
    void print(WINDOW *win) const;
};

#endif // APPLE_H
