#ifndef INFO_H
#define INFO_H


#include <cstring>
#include <ncurses.h>
#include "utilities.hpp"

class Info {
private:
    const char *about = R"(
    Tasti di scelta rapida menu:
    - n(uova partita)
    - p(unteggi)
    - i(nformazioni)
    - e(sci)
    
    Comandi in gioco:
    Le freccette corrispondono
    alle direzioni usuali, mentre
    la lettera 'p' chiama il menu
    di pausa.
    
    Premere 'e' per uscire dalla 
    pagina informazioni.)";

public:
    Info();
    void showInfo();
};

#endif // INFO_H