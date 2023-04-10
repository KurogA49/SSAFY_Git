#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct node {
	int y;
	int x;
};

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

// vector -> O(1) 시간에서 터지고 있다
// int arr[100]; -> arr[101]; -> 배열 포인터가 벗어나더라도 컴파일러가 알아서 0을 반환
// vector<int> v -> v[101]; -> 오류 발생
// -> vector[index] -> 실행되는 

struct Atom {
	int x;
	int y;
	int dir;
	int energy;
	int isAlive;
};

int N;
int map[4001][4001];
vector<Atom> v;

int main()
{
	// freopen("C:\\Users\\SSAFY\\Downloads\\sample_input (7).txt", "r", stdin);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		// reset
		memset(map, 0, sizeof(map));
		v.clear();
		int cnt = 0;
		// input
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			int x, y, dir, engy;
			cin >> x >> y >> dir >> engy;
			x = (x + 1000) * 2;
			y = (y + 1000) * 2;
			v.push_back({ x, y , dir, engy, 1 });
			map[x][y] = 1;
			cnt++;
		}
		// solve
		int ans = 0;
		while (true)
		{
			// 만약 모든 원소가 죽었다면 -> 원소가 범위를 벗어나거나 충돌할 때
			if (cnt == 0)
				break;

			// 각 원소들이 다음으로 이동할 위치를 일단 확인
			for (int i = 0; i < v.size(); i++)
			{
				Atom now = v[i];

				if (now.isAlive == 0)
					continue;
				int nx = now.x + dx[now.dir];
				int ny = now.y + dy[now.dir];

				// 방향 사용 시 항상 확인해야 할 것
				if (nx < 0 || ny < 0 || nx >= 4001 || ny >= 4001)
				{
					// 벗어났다면 원소는 죽은 것으로 처리
					v[i].isAlive = 0;
					map[now.x][now.y] = 0;
					cnt--;
					continue;
				}
				// 아직 살아 있는 원자를 움직이는 과정
				map[nx][ny]++;
				map[now.x][now.y]--;
				if (map[now.x][now.y] < 0)
					map[now.x][now.y] = 0;

				v[i].x = nx;
				v[i].y = ny;
			}

			// 모든 원자가 이동 완료
			// map -> 원소가 존재하는 위치, 즉 0보다 큰 수
			// 이 배열에 2 이상의 값이 존재한다면 -> 충돌 발생
			for (int i = 0; i < v.size(); i++)
			{
				Atom now = v[i];
				if (now.isAlive == 0)
					continue;
				// 현재 원자의 위치에 중복된 원자가 존재한다면
				if (map[now.x][now.y] >= 2)
				{
					// 그 원자들을 모두 탐색하여
					for (int j = 0; j < v.size(); j++)
					{
						if (v[j].isAlive == 0)
							continue;
						// 해당 원자를 죽이고, 에너지를 계산
						if (now.x == v[j].x && now.y == v[j].y)
						{
							v[j].isAlive = 0;
							ans += v[j].energy;
							cnt--;
						}
					}
				}
				// v[i]에 존재하는 모든 원소가 터졌으므로
				// map갱신 -> 아무 원자도 없다
				map[now.x][now.y] = 0;
			}
		}
		// output
		cout << "#" << test_case << " " << ans << "\n";
	}

	return 0;
}