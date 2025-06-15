#ifndef LEVELS_H
#define LEVELS_H

#include <iostream>

struct Livello {
  int idLivello;
  int numeroMeleDaMangiare;
  int numeroMeleMangiate;
  int tempoADisposizione;
  int tempoRimanente;
  double moltiplicatore;
  double bonus;
  double velocitaSerpente;
  bool completato;
  Livello *prev;
  Livello *next;
};

typedef Livello *livelli;

class Levels {
private:
  livelli head;
  livelli tail;
  livelli current;

public:
  Levels(int numLivelli = 10);
  ~Levels();
  livelli generaLivello(int bonus, double molt, double vel, int id);
  void generaLivelli(int numeroLivelli);
  void stampaLivelli();
  int getCurrentIndex();
  void nextLevel();
  void previusLevel();
  void gotoLevel(int num = 1);
  void completaLivello(int index);
  Livello *getCurrentLevel();
  int *getLivelliCompletati();
};

#endif // LEVELS_H
