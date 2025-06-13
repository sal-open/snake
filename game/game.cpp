#include "game.hpp"

Game::Game() {
}

void Game::startGame() {
    
    WINDOW *gameWindow = interface(HEIGHT_G, WIDTH_G);

    wrefresh(gameWindow);

    // Genera il serpente e avvia il loop
    snake.gen();
    snake.move(gameWindow);

    // Pulisce al termine
    wclear(gameWindow);
    wrefresh(gameWindow);
    delwin(gameWindow);
}
