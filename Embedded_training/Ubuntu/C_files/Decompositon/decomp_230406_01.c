#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

char vect[4][21] = {
    "DJVNIFHELSKVNDIIXNVKN",
    "MVIDIOSNVKDOPWMNVLDNE",
    "VVNJDIOZVWMVSESVPSJDS",
    "NNVIXUDNFLEPOIUDNVLXT"
};

void *encode(void *n)
{
    int num = *(int *)n;

    for (int i = 0; i < 21; i++)
    {
        vect[num][i] += 3;
        if(vect[num][i] > 'Z')
            vect[num][i] -= ('Z' - 'A');
    }
    
    return 0;
}

pthread_t tid[4];
int id[4];

int main()
{
    for (int i = 0; i < 4; i++)
    {
        id[i] = i;
        pthread_create(&tid[i], NULL, encode, &id[i]);
    }
    
    for (int i = 0; i < 4; i++)
    {
        pthread_join(tid[i], NULL);
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 21; j++)
            printf("%c", vect[i][j]);
        printf("\n");
    }
    
    return 0;
}