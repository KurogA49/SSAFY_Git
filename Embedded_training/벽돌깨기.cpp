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


int W, H, N, Max = 0;
vector<vector<int>> arr;

// W * H 판 위에 벽돌이 쌓여 있고
// N번 구슬을 쏜다
// 구슬은 좌우로만 움직이며 항상 최상위에 있는 벽돌만 깨뜨린다
// 벽돌이 깨질 시 (해당 벽돌에 적힌 숫자 - 1) 만큼의 범위로 상하좌우를 제거한다
// 벽돌은 연쇄 피해를 일으킬 수 있으며, 4만큼의 벽돌에 의해 부서진 9의 벽돌 또한 9만큼의 범위의 모든 벽돌을 부순다
// 벽돌이 부서진 뒤에 모든 벽돌은 밑으로 차근차근 내려간다
// 그럼 최대한 부수고 난 뒤에 남은 벽돌의 수는?

int countAll(vector<vector<int>> arr)
{
	int cnt = 0;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (arr[i][j] > 0)
				cnt++;
		}
	}
	return cnt;
}

vector<vector<int>> after(vector<vector<int>> arr)
{
	for (int j = 0; j < W; j++)
	{
		int last = 0;
		for (int i = H - 1; i >= 1; i--)
		{
			if (arr[i][j] == 0 && i == H - 1)
				last = i;
			else if (arr[i][j] == 0 && arr[i + 1][j] > 0)
				last = i;
			if (arr[i][j] > 0 && i < last)
			{
				int tmp = arr[i][j];
				arr[i][j] = arr[last][j];
				arr[last][j] = tmp;
				last = i - 1;
			}
		}
	}
	return arr;
}

vector<vector<int>> bfs(node start, vector<vector<int>> arr)
{
	queue<node> q;
	int dat[12][15] = {};
	q.push(start);
	dat[start.y][start.x] = 1;

	while (!q.empty())
	{
		node now = q.front(); q.pop();
		for (int i = 1; i < arr[now.y][now.x]; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int cy = now.y + i * dy[j];
				int cx = now.x + i * dx[j];

				if (cy < 0 || cx < 0 || cy >= H || cx >= W) continue;
				if (dat[cy][cx] != 0) continue;
				if (arr[cy][cx] > 0)
					q.push({ cy,cx });
				dat[cy][cx] = 1;
			}
		}
		arr[now.y][now.x] = 0;
	}
	return arr;
}

void dfs(int lev, vector<vector<int>> arr)
{
	if (lev == N)
	{
		int t = countAll(arr);
		if (Max > t)
			Max = t;
		return;
	}

	for (int i = 0; i < W; i++)
	{
		vector<vector<int>> tmp;
		tmp = arr;
		int x = i, y = -1;
		for (int j = H - 1; j >= 0; j--)
		{
			if (arr[j][i] > 0)
				y = j;
		}
		if (y >= 0)
		{
			tmp = bfs({ y, x }, tmp);
			tmp = after(tmp);
			dfs(lev + 1, tmp);
		}
	}
}

int main(int argc, char** argv)
{
	freopen("C:\\Users\\SSAFY\\Downloads\\sample_input (3).txt", "r", stdin);
	int test_case;
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N >> W >> H;
		for (int i = 0; i < H; i++)
		{
			vector<int> tmp;
			for (int j = 0; j < W; j++)
			{
				int t; cin >> t;
				tmp.push_back(t);
			}
			arr.push_back(tmp);
		}
		Max = 21e8;
		dfs(0, arr);
		cout << "#" << test_case << " " << Max << "\n";
	}

	return 0;
}