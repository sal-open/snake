
#ifndef LEVELS_H
#define LEVELS_H

#include "stdio.h"
#include "iostream"
using namespace std;
struct Livello
{
    int idLivello;            // Id numerico del livello
    int numeroMeleDaMangiare; // Si calcolano con bonus/10 * moltiplicatore
    int tempoADisposizione;   // In secondi
    double moltiplicatore;    // 1.2x per esempio, aumenta di .1x per ogni livello passato
    double bonus;             // Bonus di fine livello. Va di 50 in 50
    double velocitaSerpente;  // Velocità che aumenta ad ogni livello
    bool completato;          // Se il livello viene completato viene messo a true, usato per la grafica
    Livello *prev;
    Livello *next;
};

typedef Livello *livelli;
class Levels
{
private:
    livelli head;
    livelli tail;
    livelli current;

public:
    Levels(int numLivelli = 10)
    {
        generaLivelli(numLivelli);
        current = head;
    }

    livelli generaLivello(int bonus, double molt, double vel, int id)
    {
        livelli newLevel = new Livello();
        newLevel->idLivello = id;
        newLevel->bonus = bonus;
        newLevel->moltiplicatore = molt;
        newLevel->velocitaSerpente = vel;
        // TODO: da riguardare
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

        head = generaLivello(100, 1.0, 1.0, 1);
        livelli tmp = head;

        for (int i = 1; i < numeroLivelli; i++)
        {
            livelli nuovoLivello = generaLivello(tmp->bonus + 50, tmp->moltiplicatore + 0.1, tmp->velocitaSerpente + 0.1, tmp->idLivello + 1);
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
                 << ", ID Livello: " << tmp->idLivello
                 << ", Tempo: " << tmp->tempoADisposizione << "s\n";
            tmp = tmp->next;
        }
    }
    int getCurrentIndex()
    {
        return current->idLivello;
    }
    void nextLevel()
    {
        if (current->next != nullptr)
            current = current->next;
        else
            return;
    }
    void previusLevel()
    {
        if (current->prev != nullptr)
            current = current->prev;
        else
            return;
    }
    void gotoLevel(int num = 1)
    {
        if (num < 0)
            return;
        for (livelli tmp = head; tmp != nullptr; tmp = tmp->next)
        {
            if (tmp->idLivello == num)
            {
                current = tmp;
                break;
            }
        }
    }
    // Completando il livello viene chiamata la funzione che restituisce i punti da dare al giocatore e segna il livello come completato
    // Inoltre, aggiorna il puntatore current al successivo non completato
    void completaLivello(int index)
    {
        current->completato = true;
        // In modo che se sono al livello 2, e il livello 3 l'ho già completato, vado al 4
        while (current->completato)
        {
            current = current->next;
        }
    }
};

#endif // LEVELS_H
