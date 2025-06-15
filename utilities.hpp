#ifndef UTILITIES_H
#define UTILITIES_H
#include "ncurses.h"

#define MENU 4        // Numero di opzioni nel menu principale
#define PAUSE_MENU 11 // Numero di opzioni del menu di gioco

#define HEIGHT_M 15 // Menu
#define WIDTH_M 40
#define HEIGHT_G 20 // Game
#define WIDTH_G 70
#define HEIGHT_P 10 // Pause
#define WIDTH_P 21
#define HEIGHT_I 18 // Info
#define WIDTH_I 40

#define TIMER 300 // Il tempo per passare il livello base

struct pair {
  int x;
  int y;
};

void end();
pair getScreen();
WINDOW *interface(int height, int width);

#endif