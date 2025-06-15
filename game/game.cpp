#include "game.hpp"

Game::Game() {}

void Game::startGame() {
  start = time(nullptr);
  gameOver = false;
  punteggio = 0;

  meleMangiate = 0; // Reset del contatore mele

  gameWindow = interface(HEIGHT_G, WIDTH_G);
  wrefresh(gameWindow);
}

void Game::endGame() {
  wclear(gameWindow);
  wrefresh(gameWindow);
  delwin(gameWindow);
}

void Game::processInput() {
  nodelay(stdscr, TRUE);

  int ch = getch();

  flushinp();

  switch (ch) {
  case 'p': {
    int level = pauseMenu.run();
    if (level == 10)
      gameOver = true;
    else if (level == -1) {
      // Torna alla partita senza fare nulla
      return;
    } else {
      // Salvo il tempo rimanente del livello corrente prima di cambiare
      this->levels.getCurrentLevel()->tempoRimanente =
          levels.getCurrentLevel()->tempoADisposizione -
          (int)difftime(time(nullptr), start);

      this->levels.gotoLevel(level);
      // Imposto il tempo di inizio in base al tempo rimanente del nuovo livello
      start = time(nullptr) - (levels.getCurrentLevel()->tempoADisposizione -
                               levels.getCurrentLevel()->tempoRimanente);
      meleMangiate = this->levels.getCurrentLevel()->numeroMeleMangiate;
    }
    break;
  }
  default:
    avatar.move(gameWindow, ch, levels.getCurrentLevel()->velocitaSerpente);
  }
}

void Game::updateHeader() {
  mvwprintw(gameWindow, 0, 2, " Punteggio: %d ", punteggio);
  waddch(gameWindow, ACS_HLINE);
  wprintw(gameWindow, " Tempo: %d ", levels.getCurrentLevel()->tempoRimanente);
  waddch(gameWindow, ACS_HLINE);
  wprintw(
      gameWindow, " Mele: %d/%d ",
      meleMangiate, // Ora mostriamo le mele mangiate invece di quelle rimanenti
      levels.getCurrentLevel()->numeroMeleDaMangiare);
  waddch(gameWindow, ACS_HLINE);

  // Aggiungo il numero del livello in verde
  init_pair(3, COLOR_GREEN, -1); // Definisco una nuova coppia di colori
  wattron(gameWindow, COLOR_PAIR(3));
  wprintw(gameWindow, " Livello: %d ", levels.getCurrentIndex() + 1);
  wattroff(gameWindow, COLOR_PAIR(3));

  wrefresh(gameWindow);
}

bool Game::checkTime() {
  now = time(nullptr);
  this->levels.getCurrentLevel()->tempoRimanente =
      levels.getCurrentLevel()->tempoADisposizione - (int)difftime(now, start);
  return (difftime(now, start) >= levels.getCurrentLevel()->tempoADisposizione);
}

// int x_current, int y_current sono le posizioni della mela corrente
void Game::checkForApple() {
  if (avatar.getPosition().x == app.getPosition().x &&
      avatar.getPosition().y == app.getPosition().y) {
    app.createApple();
    punteggio += 10 * levels.getCurrentLevel()->moltiplicatore;
    meleMangiate++;
    this->levels.getCurrentLevel()->numeroMeleMangiate = meleMangiate;

    // Controlla se abbiamo mangiato tutte le mele del livello
    if (meleMangiate >= levels.getCurrentLevel()->numeroMeleDaMangiare) {
      levels.completaLivello(levels.getCurrentIndex());
      levels.nextLevel();
      meleMangiate = levels.getCurrentLevel()->numeroMeleMangiate;
      start = time(nullptr);
    }
  }
}

void Game::play(int level) {
  startGame(); // Passo il parametro a startGame

  avatar.gen();
  levels.gotoLevel(level);

  // Reset del timer e delle mele quando si cambia livello
  start = time(nullptr);
  meleMangiate = 0;

  app.createApple();

  while (!gameOver) {
    gameOver = checkTime();
    processInput();
    app.print();
    checkForApple();
    updateHeader();
  }

  endGame();
}
