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

public:
    Screen();
    void init();
    void end();
    pair getScreen();
    WINDOW* interface(char flag);

    Menu menu{*this};
};

#endif //GRAPHICS_H