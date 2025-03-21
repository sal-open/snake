#include <iostream>
#include <ctime>
#include "ncurses.h"
using namespace std;
#ifndef _APPLE_H_
#define _APPLE_H_

class Apple
{
private:
    int yLoc;
    int xLoc;
    WINDOW *win;

public:
    Apple(int y, int x, WINDOW *win)
    {
        this->yLoc = y;
        this->xLoc = x;

    }
    void generateNextLocation(int maxLocY, int maxLocX)
    {
        srand(time(0));
        this->yLoc = rand() & maxLocY;
        this->xLoc = rand() & maxLocX;
        mvwprintw(win, yLoc, xLoc, "$");
    }
};
#endif