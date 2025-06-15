#include "game.hpp"

Game::Game() {}

void Game::startGame() {
    start        = time(nullptr);
    gameOver     = false;
    punteggio    = 0;
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
            if (level == 10) {
                gameOver = true;
            } else if (level == -1) {
                // Torna alla partita senza fare nulla
                return;
            } else {
                // Salvo il tempo rimanente del livello corrente
                auto curr = levels.getCurrentLevel();
                curr->tempoRimanente = curr->tempoADisposizione
                                     - static_cast<int>(difftime(time(nullptr), start));

                levels.gotoLevel(level);

                // Imposto il tempo di inizio in base al tempo rimanente del nuovo livello
                start = time(nullptr)
                      - (levels.getCurrentLevel()->tempoADisposizione
                         - levels.getCurrentLevel()->tempoRimanente);

                meleMangiate = levels.getCurrentLevel()->numeroMeleMangiate;
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
        meleMangiate,
        levels.getCurrentLevel()->numeroMeleDaMangiare
    );
    waddch(gameWindow, ACS_HLINE);

    // Aggiungo il numero del livello in verde
    init_pair(3, COLOR_GREEN, -1);
    wattron(gameWindow, COLOR_PAIR(3));
    wprintw(gameWindow, " Livello: %d ", levels.getCurrentIndex() + 1);
    wattroff(gameWindow, COLOR_PAIR(3));

    // Serve per coprire gli spazi bianchi che si vedono passando
    // da un livello superiore a uno inferiore
    whline(gameWindow, ACS_HLINE, 5);

    wrefresh(gameWindow);
}

bool Game::checkTime() {
    now = time(nullptr);
    levels.getCurrentLevel()->tempoRimanente =
        levels.getCurrentLevel()->tempoADisposizione
      - static_cast<int>(difftime(now, start));
    return difftime(now, start) >= levels.getCurrentLevel()->tempoADisposizione;
}

void Game::checkForApple() {
    auto posA = avatar.getPosition();
    auto posM = app.getPosition();

    if (posA.x == posM.x && posA.y == posM.y) {
        app.createApple();
        punteggio   += 10 * levels.getCurrentLevel()->moltiplicatore;
        meleMangiate++;
        levels.getCurrentLevel()->numeroMeleMangiate = meleMangiate;

        // Se abbiamo mangiato tutte le mele del livello
        if (meleMangiate >= levels.getCurrentLevel()->numeroMeleDaMangiare) {
            levels.completaLivello(levels.getCurrentIndex());
            levels.nextLevel();
            meleMangiate = levels.getCurrentLevel()->numeroMeleMangiate;
            start        = time(nullptr);
        }
    }
}

void Game::play(int level) {
    startGame();             // Inizializza partita
    avatar.gen();            // Genera avatar
    levels.gotoLevel(level); // Imposta livello iniziale

    // Reset timer e mele
    start        = time(nullptr);
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
