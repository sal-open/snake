// Game.hpp
#ifndef GAME_H
#define GAME_H

#include <iostream> 
#include <ncurses.h>
#include "snake.hpp"
#include "utilities.hpp"

class Game {
public:
    Game(WINDOW* parent_win);
    ~Game();

    void start_game();

private:
    Snake snake;
    WINDOW* win;
};

#endif // GAME_H
