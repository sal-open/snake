#include "levels.hpp"
using namespace std;

Levels::Levels(int numLivelli) {
  generaLivelli(numLivelli);
  current = head;
}

Levels::~Levels() {
  livelli tmp = head;
  while (tmp != nullptr) {
    livelli next = tmp->next;
    delete tmp;
    tmp = next;
  }
  head = nullptr;
  tail = nullptr;
  current = nullptr;
}

livelli Levels::generaLivello(int bonus, double molt, double vel, int id) {
  livelli newLevel = new Livello();
  newLevel->idLivello = id;
  newLevel->bonus = bonus;
  newLevel->moltiplicatore = molt;
  newLevel->velocitaSerpente = vel;
  newLevel->numeroMeleDaMangiare =
      (newLevel->bonus / 10) * newLevel->moltiplicatore;
  newLevel->tempoADisposizione = newLevel->bonus / newLevel->moltiplicatore;
  newLevel->prev = nullptr;
  newLevel->next = nullptr;
  return newLevel;
}

void Levels::generaLivelli(int numeroLivelli) {
  if (numeroLivelli <= 0)
    return;

  head = generaLivello(100, 1.0, 1.0, 0);
  livelli tmp = head;

  for (int i = 1; i < numeroLivelli; i++) {
    livelli nuovoLivello =
        generaLivello(tmp->bonus + 50, tmp->moltiplicatore + 0.1,
                      tmp->velocitaSerpente + 0.4, tmp->idLivello + 1);
    tmp->next = nuovoLivello;
    nuovoLivello->prev = tmp;
    tmp = nuovoLivello;
  }
  tail = tmp;
}

void Levels::stampaLivelli() {
  livelli tmp = head;
  while (tmp) {
    cout << "Livello " << tmp->idLivello << ": Bonus: " << tmp->bonus
         << ", Moltiplicatore: " << tmp->moltiplicatore
         << ", Velocità: " << tmp->velocitaSerpente
         << ", Mele: " << tmp->numeroMeleDaMangiare
         << ", ID Livello: " << tmp->idLivello
         << ", Tempo: " << tmp->tempoADisposizione << "s\n";
    tmp = tmp->next;
  }
}

int Levels::getCurrentIndex() { return current->idLivello; }

void Levels::nextLevel() {
  if (current->next != nullptr)
    current = current->next;
}

void Levels::previusLevel() {
  if (current->prev != nullptr)
    current = current->prev;
}

void Levels::gotoLevel(int num) {
  if (num < 0)
    return;
  for (livelli tmp = head; tmp != nullptr; tmp = tmp->next) {
    if (tmp->idLivello == num) {
      current = tmp;
      break;
    }
  }
}

void Levels::completaLivello(int index) {
  current->completato = true;
  while (current->completato) {
    current = current->next;
  }
}

Livello *Levels::getCurrentLevel() { return current; }

int *Levels::getLivelliCompletati() {
  int count = 0;
  for (livelli tmp = head; tmp != nullptr; tmp = tmp->next) {
    if (tmp->completato) {
      count++;
    }
  }

  int *livelliCompletati = new int[count + 1];
  int index = 0;

  for (livelli tmp = head; tmp != nullptr; tmp = tmp->next) {
    if (tmp->completato) {
      livelliCompletati[index] = tmp->idLivello;
      index++;
    }
  }
  
  livelliCompletati[count] = -1;

  return livelliCompletati;
}
