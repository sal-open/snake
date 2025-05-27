/*
* Bachelor's degree in Computer Science.
* 
* Course: Programmazione (00819).
* Author: Salvatore Bruzzese.
* 
* Description: Header files for engine.cpp
*/

#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <ctime>
#include <ncurses.h>
#include <unistd.h>
#include <termios.h>
#include "../utilities.hpp"

enum arrow {
    UP, DOWN, LEFT, RIGHT
};

struct snake {
    pair head;
    snake *tail;
};

class Snake {
    private:
        snake *player = new snake;
        arrow direction = UP;

        bool alive = true;

    public:
        void gen(pair window);
        void checks(pair window);
        void spawn();
        void get_Input();
        void move(WINDOW * win, pair window);
        void pop();
        void push();
};

#endif //ENGINE_H