/*
* Laurea Triennale in Informatica - Alma Mater Studiorum.
* 
* Corso: Programmazione (00819).
* Studente: Salvatore Bruzzese.
* 
* Descrizione: .
*/

#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <ctime>
#include <ncurses.h>
#include <unistd.h>
#include <termios.h>
#include "utilities.hpp"
#include "apple.hpp"

enum arrow {
    UP, DOWN, LEFT, RIGHT
};

struct snake {
    pair head;
    snake *tail;
};

class Snake {
private:
    bool alive = true;
    snake *player = new snake;
    arrow direction = UP;
    

public:
    Apple apples;
    Snake();
    void gen(pair window);
    void checkWalls();
    void checkForApple();
    void spawn();
    void getInput();
    void move(WINDOW * win, pair window);
    void pop();
    void push();
    void reset_walls();
};

#endif // SNAKE_H