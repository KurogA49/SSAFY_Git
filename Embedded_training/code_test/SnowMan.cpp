#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	int y;
	int x;
};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int arr[50][50];
int path[50][50];
int N, M, Limit;
node start, diamond;

void bfs(node start)
{
	queue<node> q;
	q.push(start);
	path[start.y][start.x] = 1;
	
	while (!q.empty())
	{
		node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int cy = now.y + dy[i];
			int cx = now.x + dx[i];
			if (cy < 0 || cy >= N || cx < 0 || cx >= M) continue;
			// 여기까지 일반적인 이동 방식
			if ((arr[cy][cx] == 1 || arr[cy][cx] == 3) && path[cy][cx] == 0)
			{
				path[cy][cx] = path[now.y][now.x] + 1;
				q.push({ cy, cx });
			}
			// 만약 수직이동이고 점프 게이지의 한도가 1보다 크다면
			if (dy[i] == 1 || dy[i] == -1)
			{
				for (int j = 1; j < Limit; j++)
				{
					int cy = now.y + dy[i] * j;
					if (cy < 0 || cy >= N || cx < 0 || cx >= M) continue;
					if ((arr[cy][cx] == 1 || arr[cy][cx] == 3) && path[cy][cx] == 0)
					{
						path[cy][cx] = path[now.y][now.x] + j;
						q.push({ cy, cx });
					}
				}
			}
		}
	}
}

void init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			path[i][j] = 0;
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				start = { i, j };
			else if (arr[i][j] == 3)
				diamond = { i, j };
		}
	}
	do {
		init();
		bfs(start);
		Limit++;
	} while (path[diamond.y][diamond.x] == 0);

	return 0;
}