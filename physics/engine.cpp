/*
* Bachelor's degree in Computer Science.
* 
* Course: Programmazione (00819).
* Author: Salvatore Bruzzese.
* 
* Description: Source code for the game's physics engine.
*/

#include "engine.hpp"

void Snake::gen(pair screen) {
    if (presence == false) {
        unsigned int seed = std::time(nullptr);
        srand(seed);

        presence = true;
        pos.x = rand() % screen.x;
        pos.y = rand() % screen.y;
    }
}

// Metodo da eseguire ad ogni frame per verificare lo status del serpente

void Snake::checks(pair screen) {

    // Per evitare che il serpente tocchi i bordi della finestra corrente.

    if (pos.x < 20) pos.x = pos.x + 20;
    else if (pos.x >= (screen.x - 20)) pos.x = pos.x - 20;

    if (pos.y < 10) pos.y = pos.y + 10;
    else if (pos.y >= (screen.y - 10)) pos.y = pos.y - 10;

}