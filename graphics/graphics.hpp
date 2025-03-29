/*
* Bachelor's degree in Computer Science.
* 
* Course: Programmazione (00819).
* Author: Salvatore Bruzzese.
* 
* Description: File di libreria per graphics.hpp.
*/

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <ncurses.h>
#include "../utilities.hpp"

class Screen {
    private:
        pair screen;

        WINDOW *win;

    public:
        void gen_Screen();

        void end_Screen();
};

#endif //GRAPHICS_H
