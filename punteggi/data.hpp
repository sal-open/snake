#include <ctime>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "ncurses.h"

class Data
{
private:
    const static int MAX_NICKNAME_SIZE = 100;
    const static int MAX_LINE_LENGTH = 256;

    time_t id;
    char nickname[MAX_NICKNAME_SIZE];
    double points;

public:
    Data() : id{time(0)}, points{0} {}

    Data(const char *new_nickname, double new_points) : id{time(0)}, points{new_points}
    {
        int x = 0;

        while (new_nickname[x] != '\0' && x < MAX_NICKNAME_SIZE - 1)
        {
            nickname[x] = new_nickname[x];
            x++;
        }

        nickname[x] = '\0';
    }
    void Save()
    {
        static bool first_save = true;
        if (first_save)
        {
            std::ofstream clear_file("dati.txt", std::ios::trunc);
            clear_file.close();
            first_save = false;
        }

        std::fstream data_file("dati.txt", std::ios::in | std::ios::out | std::ios::app);

        if (!data_file.is_open())
        {
            std::cerr << "Errore nell'aprire il file." << std::endl;
            return;
        }

        // se è vuoto, niente da controllare => scrive direttamente
        data_file.seekg(0, std::ios::end);
        if (data_file.tellg() == 0)
        {
            data_file << "ID:" << id << "\n";
            data_file << "Nickname:" << nickname << "\n";
            data_file << "Punteggio:" << points << "\n";
            data_file.close();
            return;
        }

        // riposiziono il puntatore all'inizio del file per leggere i dati
        data_file.clear(); // resetto eventuali flag di errore
        data_file.seekg(0, std::ios::beg);

        // apro il file temporaneo e cancello tutto il suo contenuto
        std::fstream temp_file("temp.txt", std::ios::in | std::ios::out | std::ios::trunc);
        if (!temp_file.is_open())
        {
            std::cerr << "Errore nell'aprire il file temporaneo." << std::endl;
            data_file.close();
            return;
        }
        time_t id_parsed;
        char nickname_parsed[MAX_NICKNAME_SIZE];
        double points_parsed;
        bool inserted = false;
        char line[MAX_LINE_LENGTH];

        // Leggo record per record
        while (data_file.peek() != EOF)
        {
            // Leggo ID
            data_file.getline(line, MAX_LINE_LENGTH);
            if (line[0] == '\0' || strncmp(line, "ID:", 3) != 0)
            {
                continue;
            }
            id_parsed = std::strtoll(line + 3, NULL, 10); // Leggo Nickname
            data_file.getline(line, MAX_LINE_LENGTH);
            if (line[0] == '\0' || strncmp(line, "Nickname:", 9) != 0)
            {
                continue;
            }
            strncpy(nickname_parsed, line + 9, MAX_NICKNAME_SIZE - 1);
            nickname_parsed[MAX_NICKNAME_SIZE - 1] = '\0'; // Leggo Punteggio
            data_file.getline(line, MAX_LINE_LENGTH);
            if (line[0] == '\0' || strncmp(line, "Punteggio:", 10) != 0)
            {
                continue;
            }
            points_parsed = std::strtod(line + 10, NULL);

            // Se il mio punteggio è maggiore e non ho ancora inserito il record
            if (this->points > points_parsed && !inserted)
            {
                // Inserisco prima il mio record (che ha punteggio più alto)
                temp_file << "ID:" << this->id << "\n";
                temp_file << "Nickname:" << this->nickname << "\n";
                temp_file << "Punteggio:" << this->points << "\n";
                inserted = true;
            }

            // Copio il record corrente
            temp_file << "ID:" << id_parsed << "\n";
            temp_file << "Nickname:" << nickname_parsed << "\n";
            temp_file << "Punteggio:" << points_parsed << "\n";
        }

        // Se non ho inserito il record (è il punteggio più basso o il file era vuoto)
        if (!inserted)
        {
            temp_file << "ID:" << this->id << "\n";
            temp_file << "Nickname:" << this->nickname << "\n";
            temp_file << "Punteggio:" << this->points << "\n";
        }

        // Chiudo e riapro per sovrascrivere il file originale
        data_file.close();
        temp_file.close();

        // Copio il contenuto temporaneo nel file originale
        std::ifstream src("temp.txt", std::ios::binary);
        std::ofstream dst("dati.txt", std::ios::binary | std::ios::trunc);

        if (src && dst)
        {
            dst << src.rdbuf();
        }
        else
        {
            std::cerr << "Errore nella copia del file temporaneo." << std::endl;
        }

        src.close();
        dst.close();
    }

    static void Print()
    {
        std::ifstream file("dati.txt");

        if (!file.is_open())
        {
            std::cerr << "Errore nell'aprire il file." << std::endl;
            return;
        }

        char line[MAX_LINE_LENGTH];
        while (file.peek() != EOF)
        {
            // Stampa ogni riga del file
            file.getline(line, MAX_LINE_LENGTH);
            std::cout << line << std::endl;
        }
        file.close();

        std::cout << "Dati stampati correttamente." << std::endl;
    }
void mostraPunteggi()
{
    initscr();
    clear();
    noecho();
    cbreak();

    const int win_height = 25;
    const int win_width = 50;
    int starty = (LINES - win_height) / 2;
    int startx = (COLS - win_width) / 2;

    WINDOW* win = newwin(win_height, win_width, starty, startx);
    keypad(win, true);
    box(win, 0, 0);
    refresh();
    wrefresh(win);

    std::ifstream file("dati.txt");

    if (!file.is_open())
    {
        mvwprintw(win, 1, 2, "Errore nell'aprire il file dei punteggi.");
        wrefresh(win);
        getch();
        delwin(win);
        endwin();
        return;
    }

    const int MAX_LINE_LENGTH = 256;
    char line[MAX_LINE_LENGTH];
    char nickname[MAX_NICKNAME_SIZE];
    double points;
    int row = 2;

    mvwprintw(win, row++, 2, "+----------------------+------------+");
    mvwprintw(win, row++, 2, "|      Nickname        | Punteggio  |");
    mvwprintw(win, row++, 2, "+----------------------+------------+");

    while (file.peek() != EOF && row < win_height - 3)
    {
        file.getline(line, MAX_LINE_LENGTH); // Skip ID

        file.getline(line, MAX_LINE_LENGTH); // Nickname
        if (strncmp(line, "Nickname:", 9) != 0)
            continue;
        strncpy(nickname, line + 9, MAX_NICKNAME_SIZE - 1);
        nickname[MAX_NICKNAME_SIZE - 1] = '\0';

        file.getline(line, MAX_LINE_LENGTH); // Punteggio
        if (strncmp(line, "Punteggio:", 10) != 0)
            continue;
        points = std::strtod(line + 10, NULL);

        mvwprintw(win, row++, 2, "| %-20s | %10.2f |", nickname, points);
    }

    mvwprintw(win, row++, 2, "+----------------------+------------+");
    mvwprintw(win, row++, 2, "Premi un tasto per tornare al menu...");
    wrefresh(win);
    getch();
    delwin(win);
    endwin();
}
};
