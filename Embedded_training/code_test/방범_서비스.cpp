#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct node {
	int y;
	int x;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int N, M;
int arr[20][20];

int getDistance(int y1, int x1, int y2, int x2)
{
	int dify = y1 - y2 > 0 ? y1 - y2 : y2 - y1;
	int difx = x1 - x2 > 0 ? x1 - x2 : x2 - x1;

	return dify + difx;
}

int bfs(node start)
{
	// 손해를 보지 않는 선에서 최대한 커버 가능한 주택 수를 반환
	// 만약 손해를 본다면 0을 반환
	queue<node> q;
	int path[20][20] = {};
	int cnt = 0;
	q.push(start);
	path[start.y][start.x] = 1;
	int coverage = 1;
	int temp = 0;
	if (arr[start.y][start.x] == 1)
		cnt++;
	if (M * cnt - coverage >= 0)
		temp = cnt;

	while (!q.empty())
	{
		coverage++;
		int cursize = q.size();
		for (int j = 0; j < cursize; j++)
		{
			node now = q.front(); q.pop();
			for (int i = 0; i < 4; i++)
			{
				int cy = now.y + dy[i];
				int cx = now.x + dx[i];
				if (cy < 0 || cy >= N || cx < 0 || cx >= N) continue;
				if (path[cy][cx] > 0) continue;
				if (arr[cy][cx] == 1)
					cnt++;
				q.push({ cy, cx });
				path[cy][cx] = path[now.y][now.x] + 1;
			}
			int totalCost = M * cnt - (coverage * coverage + (coverage - 1) * (coverage - 1));
			if (totalCost >= 0)
				if (cnt > temp)
					temp = cnt;
		}
	}
	
	return temp;
}

int main(int argc, char** argv)
{
	freopen("C:\\Users\\SSAFY\\Downloads\\sample_input (2).txt", "r", stdin);
	int test_case;
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}

		int max = 0;
		// 모든 도시 구획에 대해,
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				// 해당 위치 및 범위에서 커버 가능한 주택 수가 최대라면 갱신
				int t = bfs({ i, j });
				if (max < t)
					max = t;
			}
		}
		cout << "#" << test_case << " " << max << "\n";
	}

	return 0;
}