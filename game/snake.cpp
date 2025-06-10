/*
* Laurea Triennale in Informatica - Alma Mater Studiorum.
* 
* Corso: Programmazione (00819).
* Studente: Salvatore Bruzzese.
* 
* Descrizione: .
*/

#include "snake.hpp"
#include <ncurses.h>

Snake::Snake() {}

// Metodo per generare le cordinate iniziali



void Snake::gen(pair window)
{
    snake *tmp = player;

    // Calcola il centro della finestra di gioco
    int center_y = HEIGHT_G / 2;
    int center_x = WIDTH_G / 2;

    for (int i = 0; i < 4; i++)
    {
        tmp->head.y = center_y + i;
        tmp->head.x = center_x;
        
        if (i < 3)
        {
            tmp->tail = new snake;
            tmp = tmp->tail;
        }
        else
        {
            tmp->tail = nullptr;
        }
    }

    this->spawn();
}

// Metodo per visualizzare il corpo del serpente

void Snake::spawn()
{
    snake *tmp = player;

    init_pair(1, COLOR_GREEN, -1);

    while (tmp != nullptr)
    {
        attron(COLOR_PAIR(1));
        mvaddch(tmp->head.y, tmp->head.x, (tmp == player ? '@' : '#'));
        attroff(COLOR_PAIR(1));
        tmp = tmp->tail;
    }
    
}

// Metodo per verificare lo status del serpente

void Snake::checkWalls()
{
    //TODO: sistemare il comportamento di reset wall per fare in modo che si 
    // attivi solo quando il serpente è sopra il bordo
    this->reset_walls();
    // Controllo dei bordi orizzontali
    if (player->head.x <= 0){
        player->head.x = WIDTH_G - 2;
    }
    else if (player->head.x >= WIDTH_G - 1){
        player->head.x = 2;
    }

    // Controllo dei bordi verticali
    if (player->head.y <= 0){
        player->head.y = HEIGHT_G - 2;
    }
    else if (player->head.y >= HEIGHT_G - 1){
        player->head.y = 2;
    }
        
}

// int x_current, int y_current sono le posizioni della mela corrente
void Snake::checkForApple(){
    // Prendiamo le coordinate della mela corrente
    // TODO: trovare il modo di non chiamare la funzione ad ogni movimento - Passo e chiudo, buonanotte.
    coordinate coordMela = this->apples.getCurrentCoordinate();
    // se la testa del player si trova nella posizione giusta
    if(player->head.y == coordMela.posY && player->head.x == coordMela.posY){
        // chiama la funzione che toglie la mela dalla lista e restituisce la seconda

    }
}

// Metodo per ricevere l'input da tastiera

void Snake::getInput()
{
    nodelay(stdscr, TRUE);

    int ch = getch();

    flushinp();
    switch (ch)
    {
    case 'q':                   // Quit
        alive = false;
        break;
    case 'p':                   // Pause
        while (getch() != 'p') {};
        break;
    case KEY_UP:
        if (direction != DOWN)
            direction = UP;
        break;
    case KEY_DOWN:
        if (direction != UP)
            direction = DOWN;
        break;
    case KEY_LEFT:
        if (direction != RIGHT)
            direction = LEFT;
        break;
    case KEY_RIGHT:
        if (direction != LEFT)
            direction = RIGHT;
        break;
    }
}

void Snake::move(WINDOW *win, pair window)
{
    while (alive)
    {
        this->getInput();
        napms(200);

        this->pop();
        this->push();
        this->spawn();

        this->checkWalls();

        wrefresh(win);
        
    }
}

void Snake::reset_walls(){
    WINDOW* win_game = newwin(HEIGHT_G, WIDTH_G, 0, 0);
    box(win_game, 0, 0);
    wrefresh(win_game);
}

void Snake::pop()
{
    snake *tmp = player;
    snake *prev = nullptr;

    while (tmp->tail != nullptr)
    {
        prev = tmp;
        tmp = tmp->tail;
    }

    mvaddch(tmp->head.y, tmp->head.x, ' ');
    prev->tail = nullptr;
}

void Snake::push()
{
    snake *new_head = new snake;
    new_head->tail = player;

    switch (direction)
    {
    case UP:
        new_head->head.y = player->head.y - 1;
        new_head->head.x = player->head.x;
        break;
    case DOWN:
        new_head->head.y = player->head.y + 1;
        new_head->head.x = player->head.x;
        break;
    case LEFT:
        new_head->head.y = player->head.y;
        new_head->head.x = player->head.x - 1;
        break;
    case RIGHT:
        new_head->head.y = player->head.y;
        new_head->head.x = player->head.x + 1;
        break;
    }

    player = new_head;
}