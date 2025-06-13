#include "game.hpp"

Game::Game() {
}

void Game::startGame() {
    
    gameWindow = interface(HEIGHT_G, WIDTH_G);
    wrefresh(gameWindow);
}

void Game::endGame() {
    wclear(gameWindow);
    wrefresh(gameWindow);
    delwin(gameWindow);
}

void Game::processInput() {
    nodelay(stdscr, TRUE);

    int ch = getch();

    flushinp();

    switch (ch)
    {
    case 'p':   // Pausa
        while (getch() != 'p') {
        };

        pauseMenu.run();

        break;
    default:
        avatar.move(gameWindow, ch);
    }
}

void Game::play() {
    startGame();
    
    avatar.gen();
    
    while (!gameOver) gameOver = processInput();

    endGame();
}
