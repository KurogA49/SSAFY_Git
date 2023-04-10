#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

pthread_mutex_t mlock;
pthread_t t[4];
int cnt;

void *run()
{
    pthread_mutex_lock(&mlock);
    for (int i = 0; i < 10000; i++)
        cnt++;
    pthread_mutex_unlock(&mlock);

    return 0;
}

int main()
{
    pthread_mutex_init(&mlock, NULL);
    for (int i = 0; i < 4; i++)
    {
        pthread_create(&t[i], NULL, run, NULL);
        usleep(100);
    }

    for (int i = 0; i < 4; i++)
    {
        pthread_join(t[i], NULL);
    }

    pthread_mutex_destroy(&mlock);
    printf("%d\n", cnt);
    return 0;
}