#include "game.hpp"

Game::Game(WINDOW* parent_win)
  : win(parent_win)
{
    // Crea la finestra di gioco all’interno della parent
    snake.win_game = newwin(HEIGHT_G, WIDTH_G, 0, 0);
}

Game::~Game() {
    // Dealloca la finestra di gioco
    if (snake.win_game) {
        delwin(snake.win_game);
        snake.win_game = nullptr;
    }
}

void Game::start_game() {
    clear();
    refresh();

    // Dimensioni della finestra di gioco
    pair window_dims;
    WINDOW* win_game = newwin(HEIGHT_G, WIDTH_G, 0, 0);
    box(win_game, 0, 0);
    getmaxyx(win_game, window_dims.y, window_dims.x);
    wrefresh(win_game);

    // Genera il serpente e avvia il loop
    snake.gen(window_dims);
    snake.move(win_game, window_dims);

    // Pulisce al termine
    delwin(win_game);
    clear();
    refresh();
}
