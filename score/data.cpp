#include "data.hpp"

// Costruttori
Data::Data() : id{time(nullptr)}, points{0} {
}

Data::Data(const char *new_username, double new_points) : id{time(0)}, points{new_points}
{
    int x = 0;
    while (new_username[x] != '\0' && x < NAME_SIZE - 1)
    {
        username[x] = new_username[x];
        x++;
    }
    username[x] = '\0';
}

// Salvataggio punteggi
void Data::save()
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
        data_file << "username:" << username << "\n";
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
    char username_parsed[NAME_SIZE];
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
        id_parsed = std::strtoll(line + 3, NULL, 10); // Leggo username
        data_file.getline(line, MAX_LINE_LENGTH);
        if (line[0] == '\0' || strncmp(line, "username:", 9) != 0)
        {
            continue;
        }
        strncpy(username_parsed, line + 9, NAME_SIZE - 1);
        username_parsed[NAME_SIZE - 1] = '\0'; // Leggo Punteggio
        data_file.getline(line, MAX_LINE_LENGTH);
        if (line[0] == '\0' || strncmp(line, "Punteggio:", 10) != 0)
        {
            continue;
        }
        points_parsed = std::strtod(line + 10, NULL);

        // Se il mio punteggio è maggiore e non ho ancora inserito il record
        if (points > points_parsed && !inserted)
        {
            // Inserisco prima il mio record (che ha punteggio più alto)
            temp_file << "ID:" << id << "\n";
            temp_file << "username:" << username << "\n";
            temp_file << "Punteggio:" << points << "\n";
            inserted = true;
        }

        // Copio il record corrente
        temp_file << "ID:" << id_parsed << "\n";
        temp_file << "username:" << username_parsed << "\n";
        temp_file << "Punteggio:" << points_parsed << "\n";
    }

    // Se non ho inserito il record (è il punteggio più basso o il file era vuoto)
    if (!inserted)
    {
        temp_file << "ID:" << id << "\n";
        temp_file << "username:" << username << "\n";
        temp_file << "Punteggio:" << points << "\n";
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

// Stampa su finestra ncurses
void Data::mostra()
{

    score = interface(HEIGHT_C, WIDTH_C);

    std::ifstream file("dati.txt");

    if (!file.is_open())
    {
        mvwprintw(score, 1, 2, "Errore nell'aprire il file dei punteggi.");
        mvwprintw(score, HEIGHT_C - 2, 2, "Premere 'e' per tornare al menu");
        wrefresh(score);
        while (getch() != 'e') {
        }
        delwin(score);
        return;
    }

    int row = 2;
    char line[MAX_LINE_LENGTH];
    char username[NAME_SIZE];
    double points;

    mvwprintw(score, 2, 4, "username");
    
    wmove(score, 2, getmaxx(score) / 2);

    waddch(score, ACS_VLINE);

    wprintw(score, " Punteggio");

    // Aggiungi un contatore per limitare il numero di punteggi visualizzati
    int count = 0;
    const int MAX_SCORES_TO_DISPLAY = 10;

    while (file.peek() != EOF && row < getmaxy(score) - 3 && count < MAX_SCORES_TO_DISPLAY)
    {
        // Leggi ID
        file.getline(line, MAX_LINE_LENGTH);
        if (line[0] == '\0' || strncmp(line, "ID:", 3) != 0) continue;

        // Leggi username
        file.getline(line, MAX_LINE_LENGTH);
        if (line[0] == '\0' || strncmp(line, "username:", 9) != 0) continue;
        strncpy(username, line + 9, NAME_SIZE - 1);
        username[NAME_SIZE - 1] = '\0';

        // Leggi Punteggio
        file.getline(line, MAX_LINE_LENGTH);
        if (line[0] == '\0' || strncmp(line, "Punteggio:", 10) != 0) continue;
        points = std::strtod(line + 10, NULL);

        mvwprintw(score, row++, 2, "| %-20s | %10.2f |", username, points);
        count++;
    }

    mvwprintw(score, HEIGHT_C - 3, 4, "Premere 'e' per tornare al menu.");
    wrefresh(score);

    while (getch() != 'e') {
    }

    wclear(score);
    wrefresh(score);
    delwin(score);
    file.close();
}