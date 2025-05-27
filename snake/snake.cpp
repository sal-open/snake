/*
* Laurea Triennale in Informatica - Alma Mater Studiorum.
* 
* Corso: Programmazione (00819).
* Studente: Salvatore Bruzzese.
* 
* Descrizione: .
*/

#include "snake.hpp"

Snake::Snake() {}

// Metodo per generare le cordinate iniziali

void Snake::gen(pair window)
{
    snake *tmp = player;

    for (int i = 0; i < 4; i++)
    {
        tmp->head.y = window.y - HEIGHT / 2 + i;
        tmp->head.x = window.x - WIDTH / 2;
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

void Snake::checks(pair window)
{
    if (player->head.x <= window.x - WIDTH)
        player->head.x = window.x - 3;
    else if (player->head.x >= window.x - 2)
        player->head.x = window.x - WIDTH + 2;

    if (player->head.y <= window.y - HEIGHT)
        player->head.y = window.y - 3;
    else if (player->head.y >= window.y - 2)
        player->head.y = window.y - HEIGHT;
}

// Metodo per ricevere l'input da tastiera

void Snake::get_Input()
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
        this->get_Input();
        napms(200);

        this->pop();
        this->push();
        this->spawn();

        this->checks(window);

        wrefresh(win);
    }
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