#include "graphics/graphics.hpp"
#include "physics/engine.hpp"

int main() {
    Screen main_scr;
    
    main_scr.gen_Screen();

    while (getch() != 'q') {}
    
    main_scr.end_Screen();
}