#include "apple.hpp"

Apple::Apple() {
}

void Apple::createApple() {
    pair screenSize = getScreen();
    pair offset;

    offset.y = (screenSize.y - HEIGHT_G) / 2;
    offset.x = (screenSize.x - WIDTH_G) / 2;

    apples.coord.y =  1 + offset.y + rand() % (HEIGHT_G - 2); // evita bordo superiore/inferiore
    apples.coord.x = 1 + offset.x + rand() % (WIDTH_G - 2);  // evita bordo sinistro/destro
}

pair Apple::getPosition() const {
    return apples.coord;
}

void Apple::print() const {
    init_pair(2, COLOR_RED, -1);
    attron(COLOR_PAIR(2));
    mvaddch(apples.coord.y, apples.coord.x, 'O');
    attroff(COLOR_PAIR(2));
    refresh();
}