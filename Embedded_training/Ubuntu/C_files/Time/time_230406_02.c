#include <stdio.h>
#include <time.h>

int main()

{
    clock_t a = clock();
    printf("%ld\n", a);

    printf("%ld\n", CLOCKS_PER_SEC);

    return 0;
}