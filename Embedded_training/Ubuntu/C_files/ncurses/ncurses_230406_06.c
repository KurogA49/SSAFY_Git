#include <ncurses.h>
#include <unistd.h>

int main()
{
    initscr();

    move(10, 50);
    printw("GAME OVER\n");
    refresh();

    sleep(2);

    endwin();
    return 0;
}