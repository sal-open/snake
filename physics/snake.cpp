/*
 * Bachelor's degree in Computer Science.
 *
 * Course: Programmazione (00819).
 * Author: Salvatore Bruzzese.
 *
 * Description: Source code for the game's physics engine.
 */

#include "snake.hpp"

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

// Metodo per creare il corpo del serpente

void Snake::spawn()
{
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    snake *tmp = player;

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

// Metodo per definire la direzione del serpente

void Snake::get_Input()
{
    nodelay(stdscr, TRUE); // Input non bloccante

    int ch = getch();
    switch (ch)
    {
    case 'q': // Quit
        alive = false;
        break;
    case 'p':                   // Pause
        nodelay(stdscr, FALSE); // Torna a input bloccante
        while (getch() != 'p')
        {
        };
        nodelay(stdscr, TRUE); // Torna a non bloccante
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
        usleep(50000);

        this->get_Input();

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