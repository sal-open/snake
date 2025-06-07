#include "info.hpp"

Info::Info() {
}

void Info::showInfo() {
    WINDOW * infoWindow = interface(HEIGHT_I, WIDTH_I);

    mvwaddstr(infoWindow, 1, 1, about);

    box(infoWindow, 0, 0);

    wrefresh(infoWindow);
    
    while (getch() != 'e') {
    }

    wclear(infoWindow);
    wrefresh(infoWindow);
    delwin(infoWindow);
}