#include <iostream>
#include <ncurses.h>
#include "utilities.hpp"

void end() {
    endwin();
    exit(0);
}

pair getScreen() {
    pair screenSize;
    getmaxyx(stdscr, screenSize.y, screenSize.x);
    return screenSize;
}

// Funzione di creazione finestra con misure desiderate

WINDOW* interface(int height, int width) {
    pair screenSize = getScreen();

    // Calcola le coordinate del centro dello schermo
    int startY = (screenSize.y - height) / 2;
    int startX = (screenSize.x - width) / 2;

    // Crea la finestra centrata
    WINDOW *win = newwin(height, width, startY, startX);
    box(win, 0, 0);
    wrefresh(win);

    return win;
}