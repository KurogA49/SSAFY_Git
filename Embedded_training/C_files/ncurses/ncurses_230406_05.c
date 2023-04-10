#include <ncurses.h>
#include <unistd.h>

int main()
{
    initscr();

    while (1)
    {
        for (int i = 0; i < 30; i++)
        {
            printw("#");
            refresh();
            usleep(10 * 1000);
        }
        
        for (int i = 30; i > 0; i--)
        {
            clear();
            for (int j = 0; j < i; j++)
            {
                printw("#");
            }
            usleep(10 * 1000);
            refresh();
        }
    }

    endwin();
}