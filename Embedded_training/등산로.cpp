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

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

// 가장 높은 봉우리에서 시작
// 높은 지형에서 낮은 지형으로 가로 또는 세로 방향으로 연결
// 최대 공사 가능 깊이는 K
// 가장 길게 공사할 수 있는 등산로의 길이는?

int N, K, Max;
int mountain[8][8];
int path[8][8];
vector<node> track;
bool flag = true;

void dfs(node now, int lev)
{
	for (int i = 0; i < 4; i++)
	{
		int cy = now.y + dy[i];
		int cx = now.x + dx[i];

		if (cy < 0 || cx < 0 || cy >= N || cx >= N) continue;
		if (path[cy][cx] != 0) continue;
		if (mountain[cy][cx] >= mountain[now.y][now.x])
		{
			if (flag)
			{
				mountain[cy][cx] -= K;
				int tmp = mountain[cy][cx];
				flag = false;
				if (mountain[cy][cx] < mountain[now.y][now.x])
				{
					mountain[cy][cx] = mountain[now.y][now.x] - 1;
					track.push_back({ cy,cx });
					path[cy][cx]++;
					dfs({ cy,cx }, lev + 1);
					path[cy][cx]--;
					track.pop_back();
					mountain[cy][cx] = tmp;
				}
				flag = true;
				mountain[cy][cx] += K;
			}
		}
		else 
		{
			track.push_back({ cy, cx });
			path[cy][cx]++;
			dfs({ cy, cx }, lev + 1);
			path[cy][cx]--;
			track.pop_back();
		}
		
	}
	if (lev > Max)
		Max = lev;
}

void init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			path[i][j] = 0;
		}
	}
}

int main()
{
	// freopen("C:\\Users\\User\\Downloads\\sample_input (1).txt", "r", stdin);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N >> K;
		int max = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> mountain[i][j];
				if (max < mountain[i][j])
					max = mountain[i][j];
			}
		}
		Max = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (mountain[i][j] == max)
				{
					path[i][j]++;
					track.push_back({ i, j });
					dfs({ i, j }, 1);
					track.pop_back();
					path[i][j]--;
				}
			}
		}
		cout << "#" << test_case << " " << Max << "\n";
	}

	return 0;
}