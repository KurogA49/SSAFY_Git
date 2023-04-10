#include <stdio.h>
#include <time.h>

int main()
{
    clock_t a = clock();
    for (int i = 0; i < 100000000; i++) {}
    clock_t b = clock();
    printf("[time : %fs]\n", (b - a) / 1000000.0);

    return 0;
}