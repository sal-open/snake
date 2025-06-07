#ifndef INFO_H
#define INFO_H


#include <cstring>
#include "screen.hpp"
#include "../utilities.hpp"

class Info {
private:
    Screen &terminal;
    const char* about = R"(
    Tasti di scelta rapida:
    n(uova partita) - p(unteggi)
    i(informazioni) - e(sci).

    Comandi in gioco:
    Le freccette corrispondono
    alle direzioni usuali, mentre
    la lettera 'p' chiama il menu
    di pausa.
    )";

public:
    Info(Screen &s);
    void showInfo();
};

#endif // INFO_H