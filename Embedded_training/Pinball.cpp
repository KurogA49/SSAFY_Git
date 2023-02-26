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
	int direction;
};

struct warmhole {
	int y;
	int x;
};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int alter[4] = { 1, 0, 3, 2 };

// 상하좌우 : 0 1 2 3

int transDirection[4][6] = {
	0, -1, 3, 2, -1, -1,
	1, 3, -1, -1, 2, -1,
	2, 0, 1, -1, -1, -1,
	3, -1, -1, 1, 0, -1
};

vector<vector<warmhole>> holes;
int map[102][102];
int N;

int bfs(node start)
{
	node now = start;
	int cnt = 0;

	while (1)
	{
		int block = map[now.y][now.x];
		if (block > 0 && block < 6)
		{
			cnt++;
			now.direction = transDirection[now.direction][block];
			if (now.direction == -1)
				return cnt * 2 - 1;
		}
		else if (block >= 6)
		{
			if (holes[block][0].y == now.y && holes[block][0].x == now.x)
			{
				now.y = holes[block][1].y;
				now.x = holes[block][1].x;
			}
			else
			{
				now.y = holes[block][0].y;
				now.x = holes[block][0].x;
			}
		}

		int ny = now.y + dy[now.direction];
		int nx = now.x + dx[now.direction];

		if (ny < 0 || nx < 0 || ny > N + 1 || nx > N + 1) continue;
		if (map[ny][nx] == -1) break;
		if (ny == start.y && nx == start.x) break;

		now = { ny, nx, now.direction };
	}
	return cnt;
}

int main()
{
	// freopen("C:\\Users\\User\\Downloads\\sample_input (3).txt", "r", stdin);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		holes = vector<vector<warmhole>>(11);
		cin >> N;
		for (int i = 0; i < N + 2; i++)
		{
			map[0][i] = 5;
			map[i][0] = 5;
			map[N + 1][i] = 5;
			map[i][N + 1] = 5;
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> map[i][j];
				if (map[i][j] >= 6)
				{
					holes[map[i][j]].push_back({ i, j });
				}
			}
		}
		int max = 0;
		for (int i = 0; i <= N + 1; i++)
		{
			for (int j = 0; j <= N + 1; j++)
			{
				if (map[i][j] != 0)
				{
					for (int k = 0; k < 4; k++)
					{
						int ny = i + dy[k];
						int nx = j + dx[k];
						if (ny < 0 || nx < 0 || ny > N + 1 || nx > N + 1) continue;
						if (map[ny][nx] == 0)
						{
							int t = bfs({ ny, nx, alter[k]});
							if (t > max)
								max = t;
						}

						/*for (int l = 0; l < 4; l++)
						{
							int ny = i + dy[l];
							int nx = j + dx[l];
							if (ny < 0 || nx < 0 || ny > N + 1 || nx > N + 1) continue;
							if (map[ny][nx] != 0) continue;
							int t = bfs({ ny, nx, k });
							if (max < t)
								max = t;
						}*/
					}
				}
			}
		}
		cout << "#" << test_case << " " << max << "\n";
		holes.clear();
	}

	return 0;
}