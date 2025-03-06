
#ifndef LEVELS_H
#define LEVELS_H

#include "stdio.h"
#include "iostream"
using namespace std;
struct Livello
{
    int numeroMeleDaMangiare; // Si calcolano con bonus/10 * moltiplicatore
    int tempoADisposizione;   // In secondi
    double moltiplicatore;    // 1.2x per esempio, aumenta di .1x per ogni livello passato
    double bonus;             // Bonus di fine livello. Va di 50 in 50
    double velocitaSerpente;  // Velocità che aumenta ad ogni livello
    Livello *prev;
    Livello *next;
};

typedef Livello *livelli;
class Levels
{
private:
    livelli head;
    livelli tail;

public:
    Levels(int numLivelli = 10)
    {
        generaLivelli(numLivelli);
    }
    livelli generaLivello(int bonus, double molt, double vel)
    {
        livelli newLevel = new Livello();
        newLevel->bonus = bonus;
        newLevel->moltiplicatore = molt;
        newLevel->velocitaSerpente = vel;
        newLevel->numeroMeleDaMangiare = (newLevel->bonus / 10) * newLevel->moltiplicatore;
        newLevel->tempoADisposizione = newLevel->bonus / newLevel->moltiplicatore;
        newLevel->prev = nullptr;
        newLevel->next = nullptr;
        return newLevel;
    }
    void generaLivelli(int numeroLivelli)
    {
        if (numeroLivelli <= 0)
            return;

        head = generaLivello(100, 1.0, 1.0);
        livelli tmp = head;

        for (int i = 1; i < numeroLivelli; ++i)
        {
            livelli nuovoLivello = generaLivello(tmp->bonus + 50, tmp->moltiplicatore + 0.1, tmp->velocitaSerpente + 0.1);
            tmp->next = nuovoLivello;
            nuovoLivello->prev = tmp;
            tmp = nuovoLivello;
        }
        tail = tmp;
    }
    void stampaLivelli()
    {
        livelli tmp = head;
        int livello = 1;
        while (tmp)
        {
            cout << "Livello " << livello++ << ": Bonus: " << tmp->bonus
                 << ", Moltiplicatore: " << tmp->moltiplicatore
                 << ", Velocità: " << tmp->velocitaSerpente
                 << ", Mele: " << tmp->numeroMeleDaMangiare
                 << ", Tempo: " << tmp->tempoADisposizione << "s\n";
            tmp = tmp->next;
        }
    }
};

#endif // LEVELS_H
