/*
* Bachelor's degree in Computer Science.
* 
* Course: Programmazione (00819).
* Author: Salvatore Bruzzese.
* 
* Description: Source code for the game's visual grid management.
*/

#include "graphics.hpp"

void Screen::init() {
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    refresh();
}

void Screen::gameboard() {
    getmaxyx(stdscr, screen.y, screen.x);
    
    offset.y = screen.y/2 - HEIGHT/2;
    offset.x = screen.x/2 - WIDTH/2,

    window.y = offset.y + HEIGHT;
    window.x = offset.x + WIDTH;

    win = newwin(HEIGHT, WIDTH, offset.y, offset.x);

    nodelay(win, true);

    box(win, 0, 0);
    wrefresh(win);
}

void Screen::end(int code) {
    endwin();
    exit(code);
}

pair Screen::get_Gameboard() {
    return window;
}

WINDOW* Screen::get_Window() {
    return win;
}