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
#include "../utilities.hpp"

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
    Snake();
    void gen(pair window);
    void checks(pair window);
    void spawn();
    void getInput();
    void move(WINDOW * win, pair window);
    void pop();
    void push();
};

#endif // SNAKE_H