// Game.hpp
#ifndef GAME_H
#define GAME_H

#include <iostream> 
#include <ncurses.h>
#include "snake.hpp"
#include "pause.hpp"
#include "utilities.hpp"

class Game {
private:
    Snake avatar{};
    Pause pauseMenu{};

    WINDOW *gameWindow;

    bool gameOver = false;
    
    void startGame();
    void endGame();
    void processInput();
    bool checkTime();

public:
    Game();
    void play();    
};

#endif // GAME_H
