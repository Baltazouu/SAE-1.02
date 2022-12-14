#include <stdio.h>
#include "aff.h"

#include <ncurses.h>


void affiche(void)
{
    initscr();
    printw("j'affiche un truc\n");
    refresh();
    getch();
    endwin();
}
