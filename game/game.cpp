#include "game.hpp"

Game::Game() {
}

void Game::startGame() {
    start = time(nullptr);
    gameOver = false;

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
        if (pauseMenu.run() == 10) gameOver = true;

        break;
    default:
        avatar.move(gameWindow, ch);
    }
}

void Game::updateHeader() {
    mvwprintw(gameWindow, 0, 2, " Punteggio: %d ", punteggio);
    waddch(gameWindow, ACS_HLINE);
    wprintw(gameWindow, " Tempo: %d ", TIMER - (int)difftime(now, start));
    wrefresh(gameWindow);
}

bool Game::checkTime() {
    now = time(nullptr);
    return (difftime(now, start) >= TIMER);
}

void Game::play() {
    startGame();
    
    avatar.gen();
    
    while (!gameOver) {
        gameOver = checkTime();
        processInput();
        updateHeader();
    }

    endGame();
}
