#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

struct node {
	int y;
	int x;
};

struct cell {
	int y;
	int x;
	int life;
	int timestamp;
	bool isAlive;
};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

cell arr[351][351];
int board[351][351];
int N, M, K, X;

void cultivate()
{
	queue<cell> q;

	for (int i = 0; i < 351; i++)
	{
		for (int j = 0; j < 351; j++)
		{
			if(arr[i][j].isAlive && arr[i][j].life > 0)
				q.push(arr[i][j]);
		}
	}
	int len = q.size();
	for (int i = 0; i < len; i++)
	{
		cell now = q.front(); q.pop();
		if (now.timestamp == now.life * 2)
			arr[now.y][now.x].isAlive = false;
		arr[now.y][now.x].timestamp++;
		q.push(now);
	}
	for (int i = 0; i < len; i++)
	{
		cell now = q.front(); q.pop();
		if (now.timestamp == now.life + 1)
		{
			for (int i = 0; i < 4; i++)
			{
				int cy = now.y + dy[i];
				int cx = now.x + dx[i];

				if (cy < 0 || cx < 0 || cy >= 351 || cx >= 351) continue;
				if (arr[cy][cx].life != 0)
				{
					if (arr[cy][cx].life < now.life && arr[cy][cx].timestamp == 1)
						arr[cy][cx] = { cy, cx, now.life, 1, true };
				}
				else
					arr[cy][cx] = { cy, cx, now.life, 1, true };
			}
		}
	}
}

int main()
{
	// freopen("C:\\Users\\SSAFY\\Downloads\\sample_input (8).txt", "r", stdin);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N >> M >> K;
		for (int i = 150; i < 150 + N; i++)
		{
			for (int j = 150; j < 150 + M; j++)
			{
				int t; cin >> t;
				arr[i][j] = { i, j, t, 0, true };
			}
		}
		for (int i = 0; i <= K; i++)
		{
			cultivate();
		}
		int cnt = 0;
		for (int i = 0; i < 351; i++)
		{
			for (int j = 0; j < 351; j++)
			{
				if (arr[i][j].isAlive)
					cnt++;
			}
		}
		cout << "#" << test_case << " " << cnt << "\n";
		for (int i = 0; i < 351; i++)
		{
			for (int j = 0; j < 351; j++)
			{
				arr[i][j] = { 0, 0, 0, 0, true };
			}
		}
	}

	return 0;
}