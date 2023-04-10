#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct node {
	int y;
	int x;
};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int arr[10][10];
int N;

void bfs(node start)
{
	queue<node> q;
	q.push(start);
	arr[start.y][start.x] = 1;

	while (!q.empty())
	{
		node now = q.front();
		q.pop();

		// 1. 오른쪽으로 이동하기
		if (now.x + dx[3] >= 0 && now.x + dx[3] < N && arr[now.y][now.x + dx[3]] == 0)
		{
			q.push(node{ now.y, now.x + dx[3] });
			arr[now.y][now.x + dx[3]] = arr[now.y][now.x] + 1;
		} // 2. 아래쪽으로 이동하기
		else if (now.y + dy[1] >= 0 && now.y + dy[1] < N && arr[now.y + dy[1]][now.x] == 0)
		{
			q.push(node{ now.y + dy[1], now.x });
			arr[now.y + dy[1]][now.x] = arr[now.y][now.x] + 1;
		} // 3. 왼쪽으로 이동하기
		else if (now.x + dx[2] >= 0 && now.x + dx[2] < N && arr[now.y][now.x + dx[2]] == 0)
		{
			q.push(node{ now.y, now.x + dx[2] });
			arr[now.y][now.x + dx[2]] = arr[now.y][now.x] + 1;
		} // 4. 위쪽으로 이동하기
		else if (now.y + dy[0] >= 0 && now.y + dy[0] < N && arr[now.y + dy[0]][now.x] == 0)
		{
			q.push(node{ now.y + dy[0], now.x });
			arr[now.y + dy[0]][now.x] = arr[now.y][now.x] + 1;
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		bfs(node{ 0, 0 });

		cout << '#' << test_case << '\n';
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << arr[i][j] << " ";
				arr[i][j] = 0;
			}
			cout << '\n';
		}
	}
	return 0;
}