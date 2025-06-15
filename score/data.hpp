#ifndef DATA_H
#define DATA_H

#include <ctime>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ncurses.h>
#include "utilities.hpp"

class Data
{
private:
    WINDOW *score;

    time_t id;
    char nickname[MAX_NICKNAME_SIZE];
    double points;

    void Save();
    
    void mostraPunteggi();

public:
    Data();
    Data(const char *new_nickname, double new_points);
    void punteggio();
};

#endif // DATA_H