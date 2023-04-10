#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *DD1()
{
    while (1)
    {
        for (int i = 0; i < 3; i++)
        {
            printf("[DD1] %c\n", 'A' + i);
            usleep(300 * 1000);
        }
    }

    return 0;
}

void *DD2()
{
    while (1)
    {
        for (int i = 0; i <= 5; i++)
        {
            printf("[DD2] %d\n", i);
            usleep(200 * 1000);
        }
    }

    return 0;
}

void *DD3()
{
    while (1)
    {
        for (char i = 'A'; i <= 'Z'; i++)
        {
            printf("[DD3] %c\n", i);
            usleep(300 * 1000);
        }
    }

    return 0;
}

int main()
{
    pthread_t tid[3];
    void *funcset[3] = {DD1, DD2, DD3};

    for (size_t i = 0; i < 3; i++)
        pthread_create(&tid[i], NULL, funcset[i], NULL);
    
    for (size_t i = 0; i < 3; i++)
        pthread_join(tid[i], NULL);

    return 0;
}
