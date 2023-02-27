#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
	int y;
	int x;
};
struct p {
	int y;
	int x;
};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int N, M, R, C, L;
int arr[50][50];
int path[50][50];
int pipes[7] = { 1, 2, 3, 4, 5, 6, 7 };
// 교차, 상하, 좌우, 상우, 하우, 하좌, 상좌

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
			if (cy < 0 || cx < 0 || cy >= N || cx >= M) continue;
			if (arr[cy][cx] == 0) continue;
			if (path[cy][cx] != 0) continue;
			// 파이프의 모양과 상관없이 현재 위치에서 진행 방향으로의 길이 막혀 있으면 무조건 out
			// 위로 향할 땐 3번, 4번, 7번 파이프 불가
			if ((dy[i] == -1 && dx[i] == 0) && (arr[cy][cx] == pipes[2] || arr[cy][cx] == pipes[3] || arr[cy][cx] == pipes[6])) continue;
			// 아래로 향할 땐 3번 5번 6번 파이프 불가
			if ((dy[i] == 1 && dx[i] == 0) && (arr[cy][cx] == pipes[2] || arr[cy][cx] == pipes[4] || arr[cy][cx] == pipes[5])) continue;
			// 좌로 향할 땐 2번 6번 7번 파이프 불가
			if ((dy[i] == 0 && dx[i] == -1) && (arr[cy][cx] == pipes[1] || arr[cy][cx] == pipes[5] || arr[cy][cx] == pipes[6])) continue;
			// 우로 향할 땐 2번 4번 5번 파이프 불가
			if ((dy[i] == 0 && dx[i] == 1) && (arr[cy][cx] == pipes[1] || arr[cy][cx] == pipes[3] || arr[cy][cx] == pipes[4])) continue;

			// 교차형 터널이라면 모든 방향에 대해 탐색
			if (arr[now.y][now.x] == pipes[0])
			{
				path[cy][cx] = path[now.y][now.x] + 1;
				q.push({ cy, cx });
			}
			// 상하형 터널이라면 위아래만 탐색
			else if (arr[now.y][now.x] == pipes[1])
			{
				if (dx[i] != 0) continue;
				path[cy][cx] = path[now.y][now.x] + 1;
				q.push({ cy,cx });
			}
			// 좌우형 터널이라면 옆만 탐색
			else if (arr[now.y][now.x] == pipes[2])
			{
				if (dy[i] != 0) continue;
				path[cy][cx] = path[now.y][now.x] + 1;
				q.push({ cy,cx });
			}
			// 상우형 터널의 경우
			else if (arr[now.y][now.x] == pipes[3])
			{
				if ((dy[i] == 0 && dx[i] == -1) || (dy[i] == 1 && dx[i] == 0)) continue;
				path[cy][cx] = path[now.y][now.x] + 1;
				q.push({ cy,cx });
			}
			// 하우형 터널의 경우
			else if (arr[now.y][now.x] == pipes[4])
			{
				if ((dy[i] == -1 && dx[i] == 0) || (dy[i] == 0 && dx[i] == -1)) continue;
				path[cy][cx] = path[now.y][now.x] + 1;
				q.push({ cy,cx });
			}
			// 하좌형 터널의 경우
			else if (arr[now.y][now.x] == pipes[5])
			{
				if ((dy[i] == -1 && dx[i] == 0) || (dy[i] == 0 && dx[i] == 1)) continue;
				path[cy][cx] = path[now.y][now.x] + 1;
				q.push({ cy,cx });
			}
			// 상좌형 터널의 경우
			else if (arr[now.y][now.x] == pipes[6])
			{
				if ((dy[i] == 1 && dx[i] == 0) || (dy[i] == 0 && dx[i] == 1)) continue;
				path[cy][cx] = path[now.y][now.x] + 1;
				q.push({ cy,cx });
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
			arr[i][j] = 0;
			path[i][j] = 0;
		}
	}
}

int main(int argc, char** argv)
{
	// freopen("C:\\Users\\SSAFY\\Downloads\\sample_input (5).txt", "r", stdin);
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> arr[i][j];
			}
		}
		bfs({ R, C });
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (path[i][j] <= L && path[i][j] > 0)
					cnt++;
			}
		}
		cout << "#" << test_case << " " << cnt << "\n";
		init();
	}

	return 0;
}