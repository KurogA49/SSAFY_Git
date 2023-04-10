#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void gogo()
{
    printf("\nERROR\n");
    exit(1);
}

int main()
{
    signal(SIGALRM, gogo);

    while (1)
    {
        alarm(3);
        char buf[50];
        printf("INPUT >> ");
        scanf("%s", buf);
    }
}