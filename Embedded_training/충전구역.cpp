#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int y;
    int x;
	int range;
	int power;
};
struct p {
	int y;
	int x;
};

int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };

int M, A, chargeA, chargeB, Max;
vector<int> trackA, trackB;
p userA, userB;
vector<node> BC;


// 10*10 크기의 지도 위에 여러 무선 충전구역이 주어진다
// 무선 충전 구역에 대한 정보는 중심점과 충전 반경, 그리고 초당 충전량
// 충전 반경은 맨하탄 거리 이내의 범위
// 어떤 사용자가 이 구역을 돌아다닌다고 가정했을 때, 1초에 1칸씩 움직인다
// 그리고 매 초마다 특정 충전 구역에 들어오면 배터리가 충전된다
// 그렇다면 두 사용자가 이 구역을 돌아다니면서 얻는 총 충전량의 최대는?
// *만약 어떤 충전 구역이 둘 이상 중복된다면 사용자는 둘 중 하나를 선택한다
// *만약 한 충전 구역에 두 사용자가 동시에 이용한다면 충전량은 균등하게 나누어 배분한다

int getDistance(int y1, int x1, int y2, int x2)
{
	int dify = y1 - y2 > 0 ? y1 - y2 : y2 - y1;
	int difx = x1 - x2 > 0 ? x1 - x2 : x2 - x1;

	return dify + difx;
}

void dfs(int lev, p userA, p userB)
{
	if (lev == M)
	{
		if (Max < chargeA + chargeB)
			Max = chargeA + chargeB;
		return;
	}

	// A와 B는 현재 구역에서 충전 가능한지 확인한 뒤 충전
	for (int i = 0; i < BC.size(); i++)
	{
		// 혹시 A와 B가 같은 충전 구역에 있는 경우도 고려하여야 함
		if (getDistance(userA.y, userA.x, BC[i].y, BC[i].x) <= BC[i].range && getDistance(userB.y, userB.x, BC[i].y, BC[i].x) <= BC[i].range)
		{
			chargeA += BC[i].power / 2;
			chargeB += BC[i].power / 2;
			userA.y += dy[trackA[lev]];
			userA.x += dx[trackA[lev]];
			userB.y += dy[trackB[lev]];
			userB.x += dx[trackB[lev]];
			dfs(lev + 1, userA, userB);
			chargeA -= BC[i].power / 2;
			chargeB -= BC[i].power / 2;
		}
		else
		{
			if (getDistance(userA.y, userA.x, BC[i].y, BC[i].x) <= BC[i].range)
			{
				chargeA += BC[i].power / 2;
				userA.y += dy[trackA[lev]];
				userA.x += dx[trackA[lev]];
				userB.y += dy[trackB[lev]];
				userB.x += dx[trackB[lev]];
				dfs(lev + 1, userA, userB);
				chargeA -= BC[i].power / 2;
			}
			if (getDistance(userB.y, userB.x, BC[i].y, BC[i].x) <= BC[i].range)
			{
				chargeB += BC[i].power / 2;
				userA.y += dy[trackA[lev]];
				userA.x += dx[trackA[lev]];
				userB.y += dy[trackB[lev]];
				userB.x += dx[trackB[lev]];
				dfs(lev + 1, userA, userB);
				chargeB -= BC[i].power / 2;
			}
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
		cin >> M >> A;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int t;
				cin >> t;
				if (i == 0)
					trackA.push_back(t);
				else if (t == 1)
					trackB.push_back(t);
			}
		}
		for (int i = 0; i < A; i++)
		{
			node t;
			cin >> t.y >> t.x >> t.range >> t.power;
			BC.push_back(t);
		}
		userA = p{ 0, 0 };
		userB = p{ 10, 10 };
		Max = 0;
		dfs(0, userA, userB);
		cout << '#' << test_case << " " << Max << '\n';
		trackA.clear();
		trackB.clear();
		BC.clear();
	}

	return 0;
}