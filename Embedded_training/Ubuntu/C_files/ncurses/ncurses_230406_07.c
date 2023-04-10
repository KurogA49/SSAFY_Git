#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    initscr();

    srand(time(NULL));

    while(1)
    {
        int y = rand() % 100;
        int x = rand() % 100;
        move(y, x);
        printw("*");
        refresh();
        usleep(1000 * 50);
    }

    getch();
    endwin();

    return 0;
}