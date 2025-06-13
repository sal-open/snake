#ifndef UITILITIES_H
#define UITILITIES_H
#include "ncurses.h"

#define MENU 4          // Number of options in the main menu
#define HEIGHT_M 15     // Menu
#define WIDTH_M 40
#define HEIGHT_G 20     // Game
#define WIDTH_G 70
#define HEIGHT_P 10     // Pause
#define WIDTH_P 20
#define HEIGHT_I 18     // Info
#define WIDTH_I 40


struct pair {
    int x;
    int y;
};

void end();
pair getScreen();
WINDOW* interface(int height, int width);

#endif