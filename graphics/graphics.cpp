/*
* Bachelor's degree in Computer Science.
* 
* Course: Programmazione (00819).
* Author: Salvatore Bruzzese.
* 
* Description: Source code for the game's visual grid management.
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

void Screen::draw_Snake(pair snake_pos) {
    mvwaddch(win, snake_pos.y, snake_pos.x, '@');
    wrefresh(win);
}