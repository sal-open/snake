/*
* Laurea Triennale in Informatica - Alma Mater Studiorum.
* 
* Corso: Programmazione (00819).
* Studente: Salvatore Bruzzese.
* 
* Descrizione: .
*/

#include "screen.hpp"

// Costruttore
Screen::Screen()
  : _screen{0, 0}, _offset{0, 0}, _gameboard{0, 0} {
}

// Inizializzazione / terminazione
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
    
    getmaxyx(stdscr, _screen.y, _screen.x);
    
    _offset.y = _screen.y/2 - HEIGHT/2;
    _offset.x = _screen.x/2 - WIDTH/2,

    _gameboard.y = _offset.y + HEIGHT;
    _gameboard.x = _offset.x + WIDTH;
}

void Screen::end()
{
    endwin();
    exit(0);
}

// Getters

pair Screen::get_Screen()
{
    return _screen;
}

pair Screen::get_Offset()
{
    return _offset;
}

pair Screen::get_Gameboard()
{
    return _gameboard;
}

// Funzione di crezione interfaccia

WINDOW* Screen::interface() {
    WINDOW* interface = newwin(HEIGHT, WIDTH, _offset.y, _offset.x);

    box(interface, 0, 0);
    wrefresh(interface);

    return interface;
}