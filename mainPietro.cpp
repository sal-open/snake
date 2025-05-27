#include <iostream>
#include <ncurses.h>
#include "levels/menu.h"
#include "levels/levels.hpp"
#include "punteggi/data.hpp"

using namespace std;

int main()
{
    initscr();
    noecho();    // impedisce di vedere i caratteri che vengono digitati
    cbreak();    // disabilita buffering dei caratteri
    curs_set(0); // disabilita il cursore

    start_color();                          // abilita i colori
    init_pair(1, COLOR_GREEN, COLOR_BLACK); // colore verde per il testo

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax); // ottiene le dimensioni della finestra

    WINDOW *menuWin = newwin(15, 40, (yMax - 15) / 2, (xMax - 40) / 2); // crea una finestra per il menu
    keypad(menuWin, true);                                              // abilita i tasti freccia nella finestra

    // Stringhe per il menu
    char newGame[] = "Nuova partita";
    char ranking[] = "Punteggi";
    char exitGame[] = "Esci";

    // Inizializza il Menu
    Menu menuItems[3] = {
        Menu(newGame, 'n'),
        Menu(ranking, 'r'),
        Menu(exitGame, 'e'),
    };

    // Chiama la classe MenuBar e la funzione per disegnare il menu
    MenuBar menuBar(menuWin, menuItems, 3);
    menuBar.draw("SN@KE");

    // Attesa dell'input dell'utente
    int ch;
    while ((ch = wgetch(menuWin)))
    {
        switch (ch)
        {
        case KEY_UP:
            menuBar.spostaSu();
            break;
        case KEY_DOWN:
            menuBar.spostaGiu();
            break;
        case 10:
        {
            int scelta = menuBar.getScelta();

            switch (scelta)
            {
            case 0:
                endwin();
                printf("Avvio nuova partita...\n");
                break;
            case 1:
            {
                Data d;
                d.mostraPunteggi(); // mantiene ncurses attivo
                // Ricrea finestra menu
                clear();
                refresh();
                menuWin = newwin(15, 40, (yMax - 15) / 2, (xMax - 40) / 2);
                keypad(menuWin, true);
                menuBar = MenuBar(menuWin, menuItems, 3);
                menuBar.draw("SN@KE");
                break;
            }
            case 2:
                endwin(); // chiude solo quando esci dal gioco
                printf("Uscita dal gioco.\n");
                return 0;
            }
            break;
        }
        }
        menuBar.draw("SN@KE");
    }

    endwin();
    return 0;
}