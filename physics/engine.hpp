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
#include "../utilities.hpp"

class Snake {
    public:
        pair pos;

        bool presence = false;

        void gen(pair screen);

        void checks(pair screen);
};

#endif //ENGINE_H
