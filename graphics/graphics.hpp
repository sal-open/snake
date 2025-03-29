/*
* Bachelor's degree in Computer Science.
* 
* Course: Programmazione (00819).
* Author: Salvatore Bruzzese.
* 
* Description: Header files for graphics.hpp.
*/

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <ncurses.h>
#include "../utilities.hpp"

class Screen {
    public:
        pair screen;

        WINDOW *win;

        void gen_Screen();

        void end_Screen();

        void draw_Snake(pair snake_pos);
};

#endif //GRAPHICS_H
