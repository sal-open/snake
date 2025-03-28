/*
 * Bachelor's degree in Computer Science.
 *
 * Course: Programmazione (00819).
 * Author: Andrei Pirva, Pietro Tombaccini e Salvatore Bruzzese.
 *
 * Description: Entry point for the compiler.
 */
#include <iostream>
#include "levels/levels.hpp"
using namespace std;
#include <ncurses.h>
#include "menu.h"
#include "apple.h"

// Larghezza e altezza della finestra
static int WIDTH;
static int HEIGHT;
static int score;
static bool gameOver = false;

int main()
{

    initscr();
    noecho();
    // Il cursore non si vede
    curs_set(0);
    int yMax, xMax;
    // Prendiamo la grandezza della finestra del terminale e la salviamo nelle due variabili
    getmaxyx(stdscr, yMax, xMax);
    WINDOW *win = newwin(yMax - 10, xMax - 10, 5, 5);
    // Inserisce un bordo
    box(win, 0, 0);
    char newGame[] = "New game";
    char ranking[] = "Ranking";
    char prova[] = "Andrei";
    Menu menus[3] = {
        Menu(newGame, 'n'),
        Menu(ranking, 'r'),
        Menu(prova, 'a'),
    };

    MenuBar menuBar = MenuBar(win, menus, 3);
    menuBar.draw();

    char ch;
    Apple a = Apple(0, 0, win);
    while ((ch = wgetch(win)))
    {
        a.generateNextLocation(yMax - 10, xMax - 10);
        menuBar.handleTrigger(ch);
        menuBar.draw();
    }
    endwin();

    // Livelli generati
    Levels livello(10);
}
