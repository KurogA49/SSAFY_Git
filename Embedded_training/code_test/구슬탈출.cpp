#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct node {
    int y;
    int x;
    char ball;

    bool operator == (node right) const
    {
        return (y == right.y && x == right.x);
    }
};

struct state {
    node blue;
    node red;
};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };


char arr[10][10];
int N, M;
node hole;
state init;

int flow(node start, int direction)
{
    arr[start.y][start.x] = '.';
    while (1)
    {
        int ny = start.y + dy[direction];
        int nx = start.x + dx[direction];
        if (arr[ny][nx] != '.')
        {
            if (init.blue.ball == start.ball)
                init.blue = start;
            else if (init.red.ball = start.ball)
                init.red = start;
            arr[start.y][start.x] = start.ball;
            return 0;
        }
        start = { ny, nx, start.ball };
        if (start == hole) return 1;
    }
}


void bfs(state start)
{
    queue<state> q;
    q.push(start);

    for (int i = 0; i < 10; i++)
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            state now = q.front(); q.pop();
            for (int k = 0; k < 4; k++)
            {
                if (flow(now.red, k) == 1)
                {
                    std::cout << i + 1;
                    return;
                }
                q.push(now);
            }
        }
    }
    std::cout << -1;
    return;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'B')
            {
                init.blue.y = i;
                init.blue.x = j;
                init.blue.ball = arr[i][j];
            }
            else if (arr[i][j] == 'R')
            {
                init.red.y = i;
                init.red.x = j;
                init.red.ball = arr[i][j];
            }
            else if (arr[i][j] == 'O')
            {
                hole.y = i;
                hole.x = j;
                hole.ball = arr[i][j];
            }
        }
    }

    bfs(init);


    return 0;
}