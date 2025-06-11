#ifndef APPLE_H
#define APPLE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include "utilities.hpp"

// Definizione dei limiti della finestra di gioco
#define MIN_X 2
#define MAX_X (WIDTH_G - 2)
#define MIN_Y 2
#define MAX_Y (HEIGHT_G - 2)

// IDEA: creiamo un oggetto mela che contiene la posizione della mela, ogni volta che
// il serpente la mangia, se ne genera una nuova in una posizione randomica
struct coordinate
{
  int posX;
  int posY;
};

struct apple
{
  coordinate coord;
};

class Apple
{
private:
  apple *apples;

public:
  Apple()
  {
    apples = new apple();  // Alloco la memoria per l'oggetto apple
    srand(time(NULL));
    createApple();
  }

  ~Apple()  // Aggiungo il distruttore per liberare la memoria
  {
    delete apples;
  }

  void createApple()
  {
    apples->coord.posX = MIN_X + (rand() % (MAX_X - MIN_X + 1));
    apples->coord.posY = MIN_Y + (rand() % (MAX_Y - MIN_Y + 1));  // Corretto da posX a posY
  }
  coordinate getCurrentCoordinate()
  {
    return apples->coord;
  }

  void print()
  {
    // Inizializza il colore rosso per le mele
    init_pair(2, COLOR_RED, -1);

    // Attiva il colore rosso
    attron(COLOR_PAIR(2));
    // Disegna la mela come un carattere 'O'
    mvaddch(apples->coord.posY, apples->coord.posX, 'O');
    // Disattiva il colore
    attroff(COLOR_PAIR(2));
  }
  void printInConsole()
  {
    std::cout << "Mela: posizione (" << apples->coord.posX << ", " << apples->coord.posY << ")" << std::endl;
  }

};

#endif