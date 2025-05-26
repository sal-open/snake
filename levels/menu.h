#ifndef _MENU_H_
#define _MENU_H_

#include <ncurses.h>
#include <cstring>

class Menu
{
private:
    int startX;
    char text[20];
    char trigger;

public:
    Menu(char text[], char trigger)
    {
        strcpy(this->text, text);
        this->trigger = trigger;
    }

    void setStartX(int pos)
    {
        this->startX = pos;
    }

    int getStartX()
    {
        return this->startX;
    }

    const char *getText()
    {
        return text;
    }

    char getTrigger()
    {
        return this->trigger;
    }
};

class MenuBar
{
private:
    WINDOW *win;
    Menu *menus;
    int numMenus;
    int selectedMenu;

public:
    MenuBar(WINDOW *win, Menu *menus, int numMenus)
    {
        this->win = win;
        this->menus = menus;
        this->numMenus = numMenus;
        this->selectedMenu = 0;
    }

    void draw(const char *titolo)
    {
        werase(win);    // cancella la finestra
        box(win, 0, 0); // disegna il bordo

        int centerX = (getmaxx(win) - strlen(titolo)) / 2; // centra il titolo
        mvwprintw(win, 1, centerX, titolo);                // scrive il titolo

        int baseY = 3;
        for (int i = 0; i < numMenus; i++)
        {
            const char *voce = this->menus[i].getText();
            int centerTextX = (getmaxx(win) - strlen(voce)) / 2;

            if (selectedMenu == i)
            {
                wattron(win, A_REVERSE | COLOR_PAIR(1));          // evidenzia + colore
                mvwprintw(win, baseY + i * 2, centerTextX, voce); // scrive la voce
                wattroff(win, A_REVERSE | COLOR_PAIR(1));         // disabilita l'evidenziazione
            }
            else
            {
                mvwprintw(win, baseY + i * 2, centerTextX, voce); // scrive la voce
            }
        }

        wrefresh(win); // aggiorna la finestra
    }

    void spostaSu()
    {
        selectedMenu = (selectedMenu - 1 + numMenus) % numMenus;
    }

    void spostaGiu()
    {
        selectedMenu = (selectedMenu + 1) % numMenus;
    }

    int getScelta()
    {
        return selectedMenu;
    }
};
#endif