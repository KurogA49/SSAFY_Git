#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct __NODE__
{
    int y;
    int x;
} Node;

void *abc(void *p)
{
    Node *a = (Node *)p;

    while (1)
    {
        printf("#%d\n", a->x);
        printf("#%d\n", a->y);
        sleep(1);
    }
}

int main()
{
    pthread_t tid;
    Node gv = {1, 2};

    pthread_create(&tid, NULL, abc, &gv);
    pthread_join(tid, NULL);
}