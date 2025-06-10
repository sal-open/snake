#ifndef DATA_H
#define DATA_H

#include <ctime>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ncurses.h>

class Data
{
private:
    static const int MAX_NICKNAME_SIZE = 100;
    static const int MAX_LINE_LENGTH = 256;

    time_t id;
    char nickname[MAX_NICKNAME_SIZE];
    double points;

public:
    Data();
    Data(const char *new_nickname, double new_points);
    void Save();
    static void Print();
    static void mostraPunteggiNcurses();
};

#endif // DATA_H