#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void *VVCC(void *arg)
{
    int d = *(int *)arg;
    printf("%d ", d);

    return 0;
}

int main()
{
    pthread_t tid[38];
    int id[38];

    for (int i = 0; i < 39; i++)
    {
        id[i] = i;
        pthread_create(&tid[i], NULL, VVCC, &id[i]);
    }

    for (int i = 0; i < 39; i++)
    {
        pthread_join(tid[i], NULL);
    }

    printf("VVCC END\n");

    return 0;
}