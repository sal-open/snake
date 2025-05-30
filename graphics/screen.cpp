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
  : _screen{0, 0} {
}

// Inizializzazione / terminazione
void Screen::init() {
    initscr();
    curs_set(0);
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    start_color();
    use_default_colors();
    refresh();
    
    getmaxyx(stdscr, _screen.y, _screen.x);
}

void Screen::end() {
    endwin();
    exit(0);
}

// Getters

pair Screen::getScreen() {
    return _screen;
}

// Funzione di crezione interfaccia

WINDOW* Screen::interface(char flag) {
    WINDOW* interface;
    pair offset{0,0};

    switch (flag)
    {
    case 'm':
        offset.y = this->getScreen().y/2 - HEIGHT_M/2;
        offset.x = this->getScreen().x/2 - WIDTH_M/2;
        interface = newwin(HEIGHT_M, WIDTH_M, offset.y, offset.x);
        break;
    case 'g':
        offset.y = this->getScreen().y/2 - HEIGHT_G/2;
        offset.x = this->getScreen().x/2 - WIDTH_G/2;
        interface = newwin(HEIGHT_G, WIDTH_G, offset.y, offset.x);
        break;
    }

    box(interface, 0, 0);
    wrefresh(interface);

    return interface;
}