#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void gogo(int num)
{
    printf("GOGO\n");
}

int main()
{
    signal(SIGUSR1, gogo);

    while(1) sleep(1);

    return 0;
}