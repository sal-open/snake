#include "pause.hpp"

Pause::Pause() {    
}

void Pause::render() {

}

int Pause::interact() {
    return 0;
}

void Pause::run() {
    menu = interface(HEIGHT_P, WIDTH_P);

    render();

    box(menu, 0, 0);
}