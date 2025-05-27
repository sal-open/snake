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
#include "../physics/snake.hpp"
#include "../utilities.hpp"

class Screen {
    private:
        pair screen;
        pair offset;
        pair window;

        WINDOW *win;

    public:
    
        Snake snake;

        pair get_Gameboard();

        WINDOW* get_Window();

        void init();

        void gameboard();

        void end(int code);
};

#endif //GRAPHICS_H