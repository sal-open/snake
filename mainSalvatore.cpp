#include "graphics/graphics.hpp"
#include "physics/engine.hpp"

int main() {
    Screen main_scr;
    Snake snake;
    
    main_scr.gen_Screen();

    snake.gen(main_scr.screen);
    snake.checks(main_scr.screen);

    main_scr.draw_Snake(snake.pos);

    getch();

    main_scr.end_Screen();
}