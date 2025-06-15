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
    char username[NAME_SIZE];
    double points;

public:
    Data();
    Data(const char *new_username, double new_points);
    void save();
    void mostra();
};

#endif // DATA_H