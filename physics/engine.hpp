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

struct pair {
    int x;
    int y;
};

class Screen {
    private:
        pair screen;
        pair snake_pos;

        WINDOW *win;

        bool snake_presence = false;


    public:
        Screen();

        void screen_size();

        void snake_gen();
};

#endif //ENGINE_H
