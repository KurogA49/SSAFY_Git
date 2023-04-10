#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <pthread.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#define N 14

pthread_mutex_t mlock;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

char map[N / 1][N] = {
    "##############",
    "#            #",
    "# #   # a^^  #",
    "#   ^ # ^  ^ #",
    "#^^ ##   ##  #",
    "#S     ^^  Y #",
    "##############"};

int ny = 1;
int nx = 1;
int mx = 2;
int my = 1;
int hp = 100;
int gotSword;

void print()
{
    clear();
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (y == ny && x == nx)
            {
                printw("@");
            }
            else if (y == my && x == mx)
            {
                printw("M");
            }
            else
                printw("%c", map[y][x]);
        }
        printw("\n");
    }
    mvprintw(7, 0, "HP : %d", hp);
    refresh();
}

void *moveMonster()
{
    srand(time(NULL));

    while (1)
    {
        int val = rand() % 4;
        int newy = my + dy[val];
        int newx = mx + dx[val];

        if (map[newy][newx] == ' ')
        {
            my = newy;
            mx = newx;
        }

        pthread_mutex_lock(&mlock);
        print();
        pthread_mutex_unlock(&mlock);

        usleep(200 * 1000);
    }
}

int main()
{
    setlocale(LC_CTYPE, "ko_KR.utf8");
    initscr();

    pthread_t tid;
    pthread_mutex_init(&mlock, NULL);
    pthread_create(&tid, NULL, moveMonster, NULL);

    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    while (1)
    {
        pthread_mutex_lock(&mlock);
        print();
        pthread_mutex_unlock(&mlock);

        int ch = getch();
        if (ch == ERR)
            ch = 0;

        if (map[ny][nx] == 'M' || hp == 0)
        {
            if (gotSword)
            {
                map[ny][nx] = ' ';
                pthread_mutex_lock(&mlock);
                pthread_join(tid, NULL);
                mvprintw(8, 0, "DESTORY!!");
                pthread_mutex_unlock(&mlock);
                refresh();
                sleep(1);
                print();
            }
            else
            {
                usleep(500 * 1000);
                pthread_mutex_lock(&mlock);
                pthread_join(tid, NULL);
                clear();
                mvprintw(3, 3, "GAME OVER");
                pthread_mutex_unlock(&mlock);
                refresh();
                sleep(1);
                break;
            }
        }
        else if (map[ny][nx] == 'Y')
        {
            pthread_join(tid, NULL);
            usleep(500 * 1000);
            pthread_mutex_lock(&mlock);
            clear();
            mvprintw(3, 3, "YOU WIN");
            mvprintw(4, 3, "SCORE : %d", hp);
            pthread_mutex_unlock(&mlock);
            refresh();
            sleep(1);
            break;
        }
        else if (map[ny][nx] == 'S')
        {
            map[ny][nx] = ' ';
            gotSword = 1;
        }
        else if (map[ny][nx] == 'a')
        {
            hp += 10;
            map[ny][nx] = ' ';
            print();
            pthread_mutex_lock(&mlock);
            mvprintw(8, 0, "RECOVERED!!");
            pthread_mutex_unlock(&mlock);
        }

        if (ch == KEY_UP)
        {
            ny--;
            if (map[ny][nx] == '#')
                ny++;

            if (map[ny][nx] == '^')
            {
                hp -= 10;
                print();
                pthread_mutex_lock(&mlock);
                mvprintw(8, 0, "DAMAGED!!");
                pthread_mutex_unlock(&mlock);
            }
        }
        else if (ch == KEY_LEFT)
        {
            nx--;
            if (map[ny][nx] == '#')
                nx++;

            if (map[ny][nx] == '^')
            {
                hp -= 10;
                print();
                pthread_mutex_lock(&mlock);
                mvprintw(8, 0, "DAMAGED!!");
                pthread_mutex_unlock(&mlock);
            }
        }
        else if (ch == KEY_DOWN)
        {
            ny++;
            if (map[ny][nx] == '#')
                ny--;

            if (map[ny][nx] == '^')
            {
                hp -= 10;
                print();
                pthread_mutex_lock(&mlock);
                mvprintw(8, 0, "DAMAGED!!");
                pthread_mutex_unlock(&mlock);
            }
        }
        else if (ch == KEY_RIGHT)
        {
            nx++;
            if (map[ny][nx] == '#')
                nx--;

            if (map[ny][nx] == '^')
            {
                hp -= 10;
                print();
                pthread_mutex_lock(&mlock);
                mvprintw(8, 0, "DAMAGED!!");
                pthread_mutex_unlock(&mlock);
            }
        }
    }

    
    getch();
    endwin();
    return 0;
}