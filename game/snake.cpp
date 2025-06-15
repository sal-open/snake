#include "snake.hpp"

Snake::Snake() {}

// Metodo per visualizzare il corpo del serpente
void Snake::spawn() {
  snake *tmp = player;

  init_pair(1, COLOR_GREEN, -1);

  attron(COLOR_PAIR(1));

  while (tmp != nullptr) {
    mvaddch(tmp->head.y, tmp->head.x, (tmp == player ? '@' : '#'));
    tmp = tmp->tail;
  }

  attroff(COLOR_PAIR(1));
}

// Metodo per generare le cordinate iniziali
void Snake::gen() {
  pair screenSize = getScreen();
  border.y = (screenSize.y - HEIGHT_G) / 2;
  border.x = (screenSize.x - WIDTH_G) / 2;

  snake *tmp = player;
  alive = true;
  direction = UP;

  // Calcola il centro della finestra di gioco
  int center_y = screenSize.y / 2;
  int center_x = screenSize.x / 2;

  for (int i = 0; i < 4; i++) {
    tmp->head.y = center_y + i;
    tmp->head.x = center_x;

    if (i < 3) {
      tmp->tail = new snake;
      tmp = tmp->tail;
    } else {
      tmp->tail = nullptr;
    }
  }

  spawn();
}

// Metodo per verificare lo status del serpente
void Snake::checkWalls() {

  // Controllo dei bordi verticali
  if (player->head.x <= border.x) {
    player->head.x = border.x + WIDTH_G - 2;
  } else if (player->head.x >= border.x + WIDTH_G - 1) {
    player->head.x = border.x + 1;
  }

  // Controllo dei bordi orizzontali
  if (player->head.y <= border.y) {
    player->head.y = border.y + HEIGHT_G - 2;
  } else if (player->head.y >= border.y + HEIGHT_G - 1) {
    player->head.y = border.y + 1;
  }
}

void Snake::setDirection(int ch) {
  switch (ch) {
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

void Snake::move(WINDOW *win, int ch, int mult) {
  if (alive) {
    setDirection(ch);
    if (direction == UP || direction == DOWN)
      napms(200 / mult); // Movimento verticale
    else
      napms(100 / mult); // Movimento orizzontale

    pop();
    push();
    checkWalls();
    spawn();

    wrefresh(win);
  }
}

void Snake::pop() {
  snake *tmp = player;
  snake *prev = nullptr;

  while (tmp->tail != nullptr) {
    prev = tmp;
    tmp = tmp->tail;
  }

  mvaddch(tmp->head.y, tmp->head.x, ' ');
  prev->tail = nullptr;
}

void Snake::push() {
  snake *new_head = new snake;
  new_head->tail = player;

  switch (direction) {
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

pair Snake::getPosition() { return player->head; }