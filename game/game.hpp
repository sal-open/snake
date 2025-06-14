// Game.hpp
#ifndef GAME_H
#define GAME_H

#include <iostream> 
#include <ncurses.h>
#include <ctime>
#include "snake.hpp"
#include "pause.hpp"
#include "utilities.hpp"

class Game {
private:
    Snake avatar{};
    Pause pauseMenu{};

    WINDOW *gameWindow;

    time_t start, now;

    bool gameOver;

    int punteggio;
    
    void startGame();
    void endGame();
    void processInput();
    bool checkTime();
    void updateHeader();

public:
    Game();
    void play();
};

#endif // GAME_H
