// Game.hpp
#ifndef GAME_H
#define GAME_H

#include <iostream> 
#include <ncurses.h>
#include "snake.hpp"
#include "utilities.hpp"

class Game {
private:
    Snake snake;

public:
    Game();
    
    void startGame();
};

#endif // GAME_H
