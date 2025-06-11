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
#include "utilities.hpp"

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
            WINDOW* win_game = newwin(HEIGHT_G, WIDTH_G, 0, 0);
            box(win_game, 0, 0);
            getmaxyx(win_game, window_dims.y, window_dims.x);
            wrefresh(win_game);
            snake.gen(window_dims);
            
            // Avviamo il loop di gioco. La funzione move bloccherà l'esecuzione
            // fino alla fine della partita
            snake.move(win_game, window_dims);

            // Pulisce lo schermo dai resti del gioco
            clear();
            refresh();
            
    }

};

#endif // GAME_H