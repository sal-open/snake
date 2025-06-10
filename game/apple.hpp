#ifndef APPLE_H
#define APPLE_H

#include "../utilities.hpp"
#include "iostream"
#include <cstdlib>
#include <ctime>
#include <ncurses.h>

// Definizione dei limiti della finestra di gioco
#define MIN_X 2
#define MAX_X (WIDTH_G - 2)
#define MIN_Y 2
#define MAX_Y (HEIGHT_G - 2)

// IDEA: creare una lista di N mele (con n preso dal
// livello->numeroMeleDaMangiare) successivamente ogni volta che si mangia una
// mela la si toglie dalla lista, quando si trova NULLPTR come next, si passa al
// livello successivo e si genera una nuova lista
struct coordinate{
    int posX;
    int posY;
};

struct apple {
  coordinate coord;
  // per struttura a linked-list
  apple *next;
};

class Apple {
private:
  apple *apples;

public:
  Apple(int n) {
    apples = nullptr;
    srand(time(NULL));
    createLinkedList(n);
  }

  void createApple(int n) {
    apples->next = nullptr;
    apples->coord.posX = MIN_X + (rand() % (MAX_X - MIN_X + 1));
    apples->coord.posX = MIN_Y + (rand() % (MAX_Y - MIN_Y + 1));
  }
  coordinate getCurrentCoordinate(){
    return apples->coord;
  }

  void createLinkedList(int n) {
    // Se n è 0 o negativo, non creiamo mele
    if (n <= 0)
      return;

    // Creiamo la prima mela
    apples = new apple;
    createApple(1);

    // Creiamo le mele successive
    apple *current = apples;
    for (int i = 1; i < n; i++) {
      current->next = new apple;
      current = current->next;
      current->coord.posX = MIN_X + (rand() % (MAX_X - MIN_X + 1));
      current->coord.posY = MIN_Y + (rand() % (MAX_Y - MIN_Y + 1));
      current->next = nullptr;
    }
  }

  void print() {
    // Inizializza il colore rosso per le mele
    init_pair(2, COLOR_RED, -1);

    // Attraversa la lista delle mele
    apple *current = apples;
    while (current != nullptr) {
      // Attiva il colore rosso
      attron(COLOR_PAIR(2));
      // Disegna la mela come un carattere 'O'
      mvaddch(current->coord.posY, current->coord.posX, 'O');
      // Disattiva il colore
      attroff(COLOR_PAIR(2));

      // Passa alla mela successiva
      current = current->next;
    }
  }
  void printInConsole() {
    apple *current = apples;
    int count = 1;

    while (current != nullptr) {
      std::cout << "Mela " << count << ": posizione (" << current->coord.posX << ", "
                << current->coord.posY << ")" << std::endl;
      current = current->next;
      count++;
    }
  }
  apple *getCurrentApple() {

    std::cout << apples->coord.posX << std::endl;
     return apples; 
    }
  void popApple() {
    if (apples != nullptr) {
      apple *temp = apples;
      apples = apples->next;
      delete temp;
    }
  }
};

#endif