#include "apple.hpp"

Apple::Apple() {
    srand(static_cast<unsigned>(time(nullptr)));
    apples = new apple;
    createApple();
}

Apple::~Apple() {
    delete apples;
}

void Apple::createApple() {
    apples->coord.posX = MIN_X + (rand() % (MAX_X - MIN_X + 1));
    apples->coord.posY = MIN_Y + (rand() % (MAX_Y - MIN_Y + 1));
}

coordinate Apple::getCurrentCoordinate() const {
    return apples->coord;
}

void Apple::print() const {
    init_pair(2, COLOR_RED, -1);
    attron(COLOR_PAIR(2));
    mvaddch(apples->coord.posY, apples->coord.posX, 'O');
    attroff(COLOR_PAIR(2));
}

void Apple::printInConsole() const {
    std::cout << "Mela: posizione ("
              << apples->coord.posX << ", "
              << apples->coord.posY << ")\n";
}
