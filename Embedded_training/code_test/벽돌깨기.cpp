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
int map[5][15][12];

// W * H 판 위에 벽돌이 쌓여 있고
// N번 구슬을 쏜다
// 구슬은 좌우로만 움직이며 항상 최상위에 있는 벽돌만 깨뜨린다
// 벽돌이 깨질 시 (해당 벽돌에 적힌 숫자 - 1) 만큼의 범위로 상하좌우를 제거한다
// 벽돌은 연쇄 피해를 일으킬 수 있으며, 4만큼의 벽돌에 의해 부서진 9의 벽돌 또한 9만큼의 범위의 모든 벽돌을 부순다
// 벽돌이 부서진 뒤에 모든 벽돌은 밑으로 차근차근 내려간다
// 그럼 최대한 부수고 난 뒤에 남은 벽돌의 수는?

// 다음 level로의 map을 사용하기 위해 이전 level의 map을 전사
void mapcpy(int lev)
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			map[lev][i][j] = map[lev - 1][i][j];
		}
	}
}

// 블록을 터뜨리고 난 뒤에 빈 공간을 정리
void ordering(int lev)
{
	queue<int> q;
	for (int i = 0; i < W; i++)
	{
		for (int j = H - 1; j >= 0; j--)
		{
			if (map[lev][j][i])
			{
				q.push(map[lev][j][i]);
				map[lev][j][i] = 0;
			}
		}
		for (int j = H - 1; !q.empty(); q.pop(), j--)
		{
			map[lev][j][i] = q.front();
		}
	}
}

// 현재 위치에서 터뜨릴 블록
int dfs(int y, int x, int lev)
{
	int gap = map[lev][y][x];
	map[lev][y][x] = 0;
	int cnt = 1;

	// 현재 블록이 가진 값만큼의 모든 범위에
	for (int i = 0; i < gap; i++)
	{
		// 상하좌우로
		for (int j = 0; j < 4; j++)
		{
			int cy = y + dy[j] * i;
			int cx = x + dx[j] * i;
			if (cy < 0 || cx < 0 || cy >= H || cx >= W) continue;
			if (map[lev][cy][cx] == 0) continue;
			// 다른 블록이 닿는다면 터뜨리는 작업을 추가
			cnt += dfs(cy, cx, lev);
		}
	}
	return cnt;
}

int run(int lev)
{
	if (lev > N) return 0;
	int cnt = 0;
	for (int i = 0; i < W; i++)
	{
		// 현재 깊이에 따라 map을 전사
		mapcpy(lev);
		bool flag = true;
		int t = 0;
		for (int j = 0; j < H; j++)
		{
			// 가로 중 i번재 줄 꼭대기의 블록을 터뜨리기
			if (map[lev][j][i])
			{
				flag = false;
				t = dfs(j, i, lev);
				break;
			}
		}
		// 터뜨릴 블록이 없었다면 이하 작업은 생략
		if (flag) continue;
		ordering(lev);
		cnt = max(cnt, run(lev + 1) + t);
	}
	return cnt;
}

int main(int argc, char** argv)
{
	// freopen("C:\\Users\\User\\Downloads\\sample_input (4).txt", "r", stdin);
	int test_case;
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N >> W >> H;
		int total = 0;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> map[0][i][j];
				if (map[0][i][j] > 0)
					total++;
			}
		}
		cout << "#" << test_case << " " << total - run(1) << "\n";
	}

	return 0;
}