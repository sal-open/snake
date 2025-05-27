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
    pair window;

    WINDOW *win;

public:
    Snake snake;
    Menu menu();

    Screen();
    pair get_Gameboard();
    WINDOW* get_Window();
    void init();
    void gameboard();
    void end(int code);
};

#endif //GRAPHICS_H