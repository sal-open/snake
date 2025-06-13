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

struct coordinate {
    int posX;
    int posY;
};

struct apple {
    coordinate coord;
};

class Apple {
public:
    Apple();
    ~Apple();

    void createApple();
    coordinate getCurrentCoordinate() const;
    void print() const;
    void printInConsole() const;

private:
    apple* apples;
};

#endif // APPLE_H
