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
    pair screenSize;
    pair border;

    bool alive = true;
    snake *player = new snake;
    arrow direction = UP;

public:    
    // Livello corrente -> 1


    // Levels levels;

    Snake();
    void gen();
    void checkWalls();
    void spawn();
    void setDirection(int ch);
    void move(WINDOW * win, int ch);
    pair getPosition();
    void pop();
    void push();
};

#endif // SNAKE_H