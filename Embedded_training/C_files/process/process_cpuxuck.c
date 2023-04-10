#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_t tid[4];

void *abc()
{
    while(1);
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        pthread_create(&tid[i], NULL, abc, NULL);
    }

    for (int i = 0; i < 4; i++)
    {
        pthread_join(tid[i], NULL);
    }
}
