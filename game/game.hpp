/*
* Laurea Triennale in Informatica - Alma Mater Studiorum.
* 
* Corso: Programmazione (00819).
* Studente: Salvatore Bruzzese, Pietro Tombaccini.
* 
* Descrizione: .
*/

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <ncurses.h>
#include "snake.hpp"
#include "../utilities.hpp"

class Game {
    private:

    public:

    //Pause pauseMenu;
    Snake snake;
    WINDOW *win;
    Game(WINDOW* w){
        this->win = w;

    }

    void start_game(){
            clear();
            refresh();
            
            // Definiamo le dimensioni della finestra principale
            pair window_dims;
            
            // Generiamo il serpente passandogli le dimensioni dello schermo
            WINDOW* win_game = interface(HEIGHT_G, WIDTH_G);
            getmaxyx(win_game, window_dims.y, window_dims.x);
            box(win_game, 0, 0);
            wrefresh(win_game);
            snake.gen(window_dims);
            
            // Avviamo il loop di gioco. La funzione `move` bloccherà l'esecuzione
            // fino alla fine della partita. Passiamo `stdscr` come finestra di gioco.
            snake.move(win_game, window_dims);

            // ---- Gioco finito, si ritorna al menu ----

            // Pulisce lo schermo dai resti del gioco
            clear();
            refresh();

            // Ridisegna il box del menu e lo aggiorna, pronto per il prossimo ciclo
            
    }

};

#endif // GAME_H