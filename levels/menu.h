#include <curses.h>
#include <cstring>

#ifndef _MENU_H_
#define _MENU_H_

class Menu
{
private:
    int startX;
    char text[20]; // Array fisso invece di puntatore
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
        this->selectedMenu = -1;

        int startingPos = 2;

        for (int i = 0; i < numMenus; i++)
        {
            this->menus[i].setStartX(startingPos);

            startingPos += strlen(menus[i].getText()) + 3;
        }
    }
    void draw()
    {
        for (int i = 0; i < numMenus; i++)
        {
            char text[20];
            strcpy(text, this->menus[i].getText());
            int startX = this->menus[i].getStartX();
            if (selectedMenu == i)
            {
                wattron(win, A_STANDOUT);
            }
            mvwprintw(win, 0, startX, text);
            wattroff(win, A_STANDOUT);
        }
    }
    void handleTrigger(char trigger)
    {
        for (int i = 0; i < numMenus; i++)
        {
            if (this->menus[i].getTrigger() == trigger)
            {
                this->selectedMenu = i;
            }
        }
    }
};

#endif