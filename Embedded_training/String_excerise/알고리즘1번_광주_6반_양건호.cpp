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

int dy[4] = { -1, -1, 1, 1 };
int dx[4] = { -1, 1, -1, 1 };

int N, K;
int arr[100][100];
long getMonsters[100][100];

void bfs(node start)
{
	for (int i = 1; i <= K; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int cy = start.y + dy[j] * i;
			int cx = start.x + dx[j] * i;
			if (cy >= N || cy < 0 || cx >= N || cx < 0) continue;
			getMonsters[start.y][start.x] += arr[cy][cx];
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	cin >> K;
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			bfs({ i, j });
			if (max < getMonsters[i][j])
				max = getMonsters[i][j];
		}
	}
	cout << max;

	return 0;
}