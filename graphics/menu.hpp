#ifndef MENU_HPP
#define MENU_HPP

#include <cstring>
#include <ncurses.h>
#include "../utilities.hpp"

class Menu {
private:
    const char* title;
    static const char* items[];
    static const char  triggers[];
    static const int   count;

    static void renderMenu(WINDOW* win, const char* title, int selected);
    static int interactMenu(WINDOW* win, const char* title);

public:
    Menu(const char* title);

    int run();
};

#endif // MENU_HPP