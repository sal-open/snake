/*
* Bachelor's degree in Computer Science.
* 
* Course: Programmazione (00819).
* Author: Salvatore Bruzzese.
* 
* Description: File di libreria per engine.cpp
*/

#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <ncurses.h>
#include "../utilities.hpp"

class Snake {
    private:
        pair screen;
        pair snake_pos;

        WINDOW *win;

        bool snake_presence = false;


    public:
        Snake();

        void screen_Size();

        void snake_Gen();

        void snake_Checks();
};

#endif //ENGINE_H
