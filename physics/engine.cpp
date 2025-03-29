/*
* Bachelor's degree in Computer Science.
* 
* Course: Programmazione (00819).
* Author: Salvatore Bruzzese.
* 
* Description: Codice sorgente per il motore fisico del gioco.
*/

#include "engine.hpp"

void Snake::screen_Size() {
    getmaxyx(win, screen.y, screen.x);
}

void Snake::snake_Gen() {
    if (snake_presence == false) {
        snake_presence = true;
        snake_pos.x = rand() % screen.x;
        snake_pos.y = rand() % screen.y;
    }
}

// Metodo da eseguire ad ogni frame per verificare lo status del serpente

void Snake::snake_Checks() {

    // Per evitare che il serpente tocchi i bordi della finestra corrente.

    if (snake_pos.x < 10) screen.x = screen.x + 10;
    else if (snake_pos.x >= (screen.x - 10)) screen.x = screen.x - 10;

    if (snake_pos.y < 20) screen.y = screen.y + 20;
    else if (snake_pos.y >= (screen.y - 20)) screen.y = screen.y - 20;


}