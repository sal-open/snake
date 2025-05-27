/*
* Laurea Triennale in Informatica - Alma Mater Studiorum.
* 
* Corso: Programmazione (00819).
* Studente: Salvatore Bruzzese.
* 
* Descrizione: .
*/

#include "graphics.hpp"

Screen::Screen() {}

void Screen::init()
{
    initscr();
    curs_set(0);
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    start_color();
    use_default_colors();
    refresh();
}

void Screen::gameboard()
{
    getmaxyx(stdscr, screen.y, screen.x);
    
    offset.y = screen.y/2 - HEIGHT/2;
    offset.x = screen.x/2 - WIDTH/2,

    window.y = offset.y + HEIGHT;
    window.x = offset.x + WIDTH;

    win = newwin(HEIGHT, WIDTH, offset.y, offset.x);

    box(win, 0, 0);
    wrefresh(win);
}

void Screen::end(int code)
{
    endwin();
    exit(code);
}

pair Screen::get_Gameboard()
{
    return window;
}

WINDOW* Screen::get_Window()
{
    return win;
}