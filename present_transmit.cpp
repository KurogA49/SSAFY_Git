#include <iostream>
#include <vector>
#include <algorithm>
#define INF 21e8
using namespace std;

struct node {
	int y;
	int x;
};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int directed[4];

vector<vector<char>> Class;
vector<vector<int>> dp;
int N, M;

int transmit(node now, int cnt)
{
	int& ret = dp[now.y][now.x];
	if (ret > 0 && ret < cnt) return ret;

	memset(directed, 0, sizeof(directed));
}

int main()
{
	node start;
	cin >> N >> M;
	Class = vector<vector<char>>(N, vector<char>(M));
	dp = vector<vector<int>>(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Class[i][j];
			if (Class[i][j] == 'S')
				start = { i, j };
		}
	}



	return 0;
}