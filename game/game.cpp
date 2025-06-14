#include "game.hpp"

Game::Game() {
}

void Game::startGame() {
    start = time(nullptr);
    gameOver = false;
    punteggio = 0;

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

// int x_current, int y_current sono le posizioni della mela corrente
void Game::checkForApple()
{
    if (avatar.getPosition().x == app.getPosition().x &&
        avatar.getPosition().y == app.getPosition().y )
    {
        app.createApple();
        punteggio += 10;
    }
}

void Game::play() {
    startGame();
    
    avatar.gen();
    
    while (!gameOver) {
        gameOver = checkTime();
        processInput();
        app.print(gameWindow);
        checkForApple();
        updateHeader();
    }

    endGame();
}
