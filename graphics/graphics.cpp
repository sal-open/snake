/*
* Bachelor's degree in Computer Science.
* 
* Course: Programmazione (00819).
* Author: Salvatore Bruzzese.
* 
* Description: Codice sorgente per la gestione della griglia visiva.
*/

#include "graphics.hpp"

void Screen::gen_Screen() {
    initscr();
    noecho();
    curs_set(0);
    refresh();

    getmaxyx(stdscr, screen.y, screen.x);

    win = newwin(screen.y - 10, screen.x - 20, 5, 10);
    box(win, 0, 0);
    wrefresh(win);
}

void Screen::end_Screen() {
    endwin();
}