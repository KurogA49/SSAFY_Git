#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handler1()
{
    printf("\n[Button Clicked]\n");
}

void handler2()
{
    system("clear");
    printf("RESET\n");
}

void handler3()
{
    printf("\nBYE\n");
    exit(0);
}

int main()
{
    setbuf(stdout, NULL);
    signal(SIGUSR1, handler1);
    signal(SIGUSR2, handler2);
    signal(SIGTERM, handler3);

    while(1)
    {
        for (char i = 'A'; i <= 'Z'; i++)
        {
            printf("%c ", i);
            usleep(1000 * 100);
        }

        for (char i = 'Z'; i >= 'A'; i--)
        {
            printf("%c ", i);
            usleep(1000 * 100);
        }
    }

    return 0;
}