/*
* Bachelor's degree in Computer Science.
* 
* Course: Programmazione (00819).
* Author: Salvatore Bruzzese.
* 
* Description: Codice sorgente per il motore fisico del gioco.
*/

#include <engine.hpp>

void Screen::screen_size() {
    getmaxyx(win, screen.y, screen.x);
}

void Screen::snake_gen() {
    if (snake_presence == false) {
        snake_presence = true;
        snake_pos.x = rand() % screen.x;
        snake_pos.y = rand() % screen.y;
    }

    // Per evitare che il serpente tocchi i bordi della finestra corrente.

    if (snake_pos.x == 0) screen.x = screen.x + 10;
    else if (snake_pos.x == screen.x) screen.x = screen.x - 10;

    if (snake_pos.y == 0) screen.y = screen.y + 20;
    else if (snake_pos.y == screen.y) screen.y = screen.y - 20;
}
