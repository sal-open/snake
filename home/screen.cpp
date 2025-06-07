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

WINDOW* Screen::interface(int height, int width) {
    pair screenSize = this->getScreen();

    // Calcola le coordinate del centro dello schermo
    int startY = screenSize.y/2 - height/2;
    int startX = screenSize.x/2 - width/2;

    // Fai la schermata (height)⋅(width)
    WINDOW* win = newwin(height, width, startY, startX);

    box(win, 0, 0);
    wrefresh(win);

    return win;
}
