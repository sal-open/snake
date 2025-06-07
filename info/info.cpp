#include "info.hpp"

Info::Info(Screen &s): terminal(s) {
}

void Info::showInfo() {
    terminal.interface(HEIGHT_I, WIDTH_I);
    
}