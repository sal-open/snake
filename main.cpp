#include "graphics/graphics.hpp"
#include "graphics/menu.hpp"
#include "levels/levels.hpp"
#include "score/data.hpp"
#include "snake/snake.hpp"

int main() {
    Screen terminal;
    
    terminal.init();
    
    terminal.gameboard();

    // terminal.snake.gen(terminal.get_Gameboard());

    // terminal.snake.move(terminal.get_Window(), terminal.get_Gameboard());

    getch();

    wclear(terminal.get_Board());
    wrefresh(terminal.get_Board());

    getch();

    terminal.end(0);
}