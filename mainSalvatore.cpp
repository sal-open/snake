#include "graphics/graphics.hpp"
#include "physics/snake.hpp"

int main() {
    Screen terminal;
    
    terminal.init();
    
    terminal.gameboard();

    terminal.snake.gen(terminal.get_Gameboard());

    terminal.snake.move(terminal.get_Window(), terminal.get_Gameboard());

    terminal.end(0);
}