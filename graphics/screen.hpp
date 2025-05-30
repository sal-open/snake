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

class Menu;

class Screen
{
private:
    pair _screen;       // Dimensioni dello schermo
    pair _offset;       // Quanto è distante la finestra dai bordi
    pair _gameboard;    // Estremi della finestra

public:
    Screen();
    void init();
    void end();
    pair get_Screen();
    pair get_Offset();
    pair get_Gameboard();
    WINDOW* interface();

    Menu menu{*this};
};

#endif //GRAPHICS_H