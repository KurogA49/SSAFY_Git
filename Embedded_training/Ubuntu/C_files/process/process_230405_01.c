#include <stdio.h>
#include <unistd.h>

int main()
{
    setbuf(stdout, NULL);
    while(1)
    {
        printf("#");
        sleep(3);
    }

    return 0;
}