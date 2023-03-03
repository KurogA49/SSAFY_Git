#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	int y;
	int x;
};

int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };

int arr[41][12][12];
int N;
int cnt, MinT, cnt2, MaxCore;
vector<node> cores;

void mapcpy(int lev)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[lev][i][j] = arr[lev - 1][i][j];
		}
	}
}

int isConnected(node start, int direction, int lev)
{
	if (start.y == 0 || start.x == 0 || start.y == N - 1 || start.x == N - 1)
		return 1;

	if (direction == 0)
		return 0;

	while (direction == 1 || direction == 2)
	{
		start.y += dy[direction];
		if (arr[lev][start.y][start.x] != 0) return 0;
		arr[lev][start.y][start.x] = 5;
		if (start.y == 0 || start.y == N - 1) return 1;
	}

	while (direction == 3 || direction == 4)
	{
		start.x += dx[direction];
		if (arr[lev][start.y][start.x] != 0) return 0;
		arr[lev][start.y][start.x] = 5;
		if (start.x == 0 || start.x == N - 1) return 1;
	}

	return 0;
}

void dfs(int lev)
{
	if (cnt2 + cores.size() - lev + 1 < MaxCore)
		return;
	if (lev > cores.size())
	{
		if (MaxCore < cnt2)
		{
			MaxCore = cnt2;
			int t = 0;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (arr[lev - 1][i][j] == 5)
						t++;
				}
			}
			MinT = t;
		}
		else if (MaxCore == cnt2)
		{
			MaxCore = cnt2;
			int t = 0;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (arr[lev - 1][i][j] == 5)
						t++;
				}
			}
			MinT = min(MinT, t);
		}
		return;
	}
	node ncore = cores[lev - 1];
	if (ncore.y == 0 || ncore.y == N - 1 || ncore.x == 0 || ncore.x == N - 1)
	{
		mapcpy(lev);
		cnt2 += 1;
		dfs(lev + 1);
		cnt2 -= 1;
	}
	else
		for (int i = 0; i < 5; i++)
		{
			mapcpy(lev);
			int t = isConnected(ncore, i, lev);
			cnt2 += t;
			dfs(lev + 1);
			cnt2 -= t;
		}
}

int main()
{
	// freopen("C:\\Users\\SSAFY\\Downloads\\sample_input (1).txt", "r", stdin);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[0][i][j];
				if(arr[0][i][j] > 0)
					cores.push_back({ i, j });
			}
		}
		MinT = 21e8;
		MaxCore = 0;
		if(cores.size() > 0)
			dfs(1);
		if (MinT != 21e8)
			cout << "#" << test_case << " " << MinT << "\n";
		else
			cout << "#" << test_case << " " << 0 << "\n";
		memset(arr, 0, sizeof(arr));
		cores.clear();
	}

	return 0;
}