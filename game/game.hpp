// Game.hpp
#ifndef GAME_H
#define GAME_H

#include <iostream> 
#include <ncurses.h>
#include <ctime>
#include "snake.hpp"
#include "pause.hpp"
#include "apple.hpp"
#include "levels/levels.hpp"
#include "utilities.hpp"

class Game {
private:
    Snake avatar{};
    Apple app{};
    Pause pauseMenu{};
    Levels levels = Levels(10);

    WINDOW *gameWindow;

    time_t start, now;

    bool gameOver;

    int punteggio;
    int meleMangiate;  // Contatore delle mele mangiate nel livello corrente
    
    void startGame(bool resetScore = true);
    void endGame();
    void processInput();
    bool checkTime();
    void checkForApple();
    void updateHeader();

public:
    Game();
    void play(int level, bool resetScore = true);
};

#endif // GAME_H
