#ifndef LEVELS_H
#define LEVELS_H

struct Livello
{
    int idLivello;
    int numeroMeleDaMangiare;
    int tempoADisposizione;
    double moltiplicatore;
    double bonus;
    double velocitaSerpente;
    bool completato;
    Livello *prev;
    Livello *next;
};

class Levels
{
private:
    Livello head;
    Livello tail;
    Livello current;

public:
    Levels(int numLivelli = 10);
    Livello generaLivello(int bonus, double molt, double vel, int id);
    void generaLivelli(int numeroLivelli);
    void stampaLivelli();
    int getCurrentIndex();
    void nextLevel();
    void previusLevel();
    void gotoLevel(int num = 1);
    void completaLivello(int index);
    Livello getCurrentLevel();
};

#endif // LEVELS_H
