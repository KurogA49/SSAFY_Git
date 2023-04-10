#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
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
	bool operator < (cell right) const
	{
		return life < right.life;
	}
};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

cell arr[651][651];
int N, M, K, X, cnt;
int sy, sx, ey, ex;

void cultivate(int time)
{
	priority_queue<cell> q;
	if (time == 0)
	{
		ey = 650; ex = 650;
		sy = 0; sx = 0;
	}
	for (int i = sy; i <= ey; i++)
	{
		for (int j = sx; j <= ex; j++)
		{
			if (arr[i][j].isAlive && arr[i][j].life > 0)
				q.push(arr[i][j]);
		}
	}
	if (time == 0)
	{
		sy = 650; sx = 650;
		ey = 0; ex = 0;
	}
	int len = q.size();
	for (int i = 0; i < len; i++)
	{
		cell now = q.top(); q.pop();

		if (now.timestamp == now.life * 2)
			arr[now.y][now.x].isAlive = false;
		arr[now.y][now.x].timestamp++;

		if (now.timestamp == now.life + 1)
		{
			for (int i = 0; i < 4; i++)
			{
				int cy = now.y + dy[i];
				int cx = now.x + dx[i];

				if (cy < 0 || cx < 0 || cy >= 650 || cx >= 650) continue;
				if (arr[cy][cx].life != 0) continue;
				arr[cy][cx] = { cy, cx, now.life, 1, true };
				if (sy > cy)
					sy = cy;
				if (sx > cx)
					sx = cx;
				if (ey < cy)
					ey = cy;
				if (ex < cx)
					ex = cx;
			}
		}
		else
		{
			if (now.y < sy)
				sy = now.y;
			if (now.x < sx)
				sx = now.x;
			if (now.y > ey)
				ey = now.y;
			if (now.x > ex)
				ex = now.x;
		}
	}
}

int main()
{
	// freopen("C:\\Users\\User\\Downloads\\sample_input (6).txt", "r", stdin);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N >> M >> K;
		for (int i = 300; i < 300 + N; i++)
		{
			for (int j = 300; j < 300 + M; j++)
			{
				int t; cin >> t;
				arr[i][j] = { i, j, t, 1, true };
			}
		}
		cnt = 0;
		
		for (int i = 0; i < K; i++)
		{
			cultivate(i);
		}
		for (int i = 0; i < 650; i++)
		{
			for (int j = 0; j < 650; j++)
			{
				if (arr[i][j].isAlive && arr[i][j].life > 0)
					cnt++;
			}
		}
		cout << "#" << test_case << " " << cnt << "\n";
		memset(arr, 0, sizeof(arr));
	}

	return 0;
}