#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void *abc(void *arg)
{
    int id = *(int *)arg;

    if(id == 1) printf("ABC\n");
    else if(id == 2) printf("MINMIN\n");
    else if(id == 3) printf("COCO\n");
    else if(id == 4) printf("KFCKFC\n");

    return 0;
}

int main()
{
    pthread_t tid[4];
    int id[4];

    for (int i = 0; i < 4; i++)
    {
        id[i] = i + 1;
        pthread_create(&tid[i], NULL, abc, &id[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        pthread_join(tid[i], NULL);
    }
    
    return 0;
}