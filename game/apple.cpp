#include "apple.hpp"

Apple::Apple() {
}

void Apple::createApple() {
    apples.coord.y = 1 + rand() % (HEIGHT_G - 2); // evita bordo superiore/inferiore
    apples.coord.x = 1 + rand() % (WIDTH_G - 2);  // evita bordo sinistro/destro
}

pair Apple::getPosition() const {
    return apples.coord;
}

void Apple::print(WINDOW *win) const {
    init_pair(2, COLOR_RED, -1);
    wattron(win, COLOR_PAIR(2));
    mvwaddch(win, apples.coord.y, apples.coord.x, 'O');
    wattroff(win, COLOR_PAIR(2));
    wrefresh(win);
}