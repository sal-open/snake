// Game.hpp
#ifndef GAME_H
#define GAME_H

#include "apple.hpp"
#include "levels/levels.hpp"
#include "pause.hpp"
#include "snake.hpp"
#include "utilities.hpp"
#include <ctime>
#include <iostream>
#include <ncurses.h>

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
  int meleMangiate; // Contatore delle mele mangiate nel livello corrente

  void startGame();
  void endGame();
  void processInput();
  bool checkTime();
  void checkForApple();
  void updateHeader();

public:
  Game();
  void play(int level);
};

#endif // GAME_H
