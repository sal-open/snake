/*
* Laurea Triennale in Informatica - Alma Mater Studiorum.
* 
* Corso: Programmazione (00819).
* Studente: Salvatore Bruzzese.
* 
* Descrizione: .
*/

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <ncurses.h>
#include "menu.hpp"
#include "../snake/snake.hpp"
#include "../utilities.hpp"

class Screen
{
private:
    pair window;        // Coordinate di box_win

    WINDOW *box_win;    // La finestra utilizzata per fare il bordo
    WINDOW *board;      // La finestra utilizzata per tutte le interazioni

public:
    Menu menu();

    Screen();
    pair get_Gameboard();
    WINDOW* get_Board();
    void init();
    void gameboard();
    void end(int code);
};

#endif //GRAPHICS_H