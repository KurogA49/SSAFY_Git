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
	int range;
	int power;
	int num;

	bool operator < (node right) const
	{
		return power > right.power;
	}
	bool operator == (node right) const
	{
		return num == right.num;
	}
};
struct p {
	int y;
	int x;
};

int dy[5] = { 0, -1, 0, 1, 0 };
int dx[5] = { 0, 0, 1, 0, -1 };

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

int getTotalPower()
{
	int power = 0;
	for (int currentTime = 0; currentTime <= M; currentTime++)
	{
		int maxA = 0;
		int maxB = 0;
		vector<node> chargeA, chargeB, chargeCommon;
		for (int i = 0; i < BC.size(); i++)
		{
			int fromA = getDistance(userA.y, userA.x, BC[i].y, BC[i].x);
			int fromB = getDistance(userB.y, userB.x, BC[i].y, BC[i].x);

			// 현재 두 사람이 충전 구역 내에 있는가?
			if (fromA <= BC[i].range && fromB <= BC[i].range)
			{
				chargeCommon.push_back(BC[i]);
			}
			else
			{
				if (fromA <= BC[i].range)
					chargeA.push_back(BC[i]);
				if (fromB <= BC[i].range)
					chargeB.push_back(BC[i]);
			}
		}
		sort(chargeA.begin(), chargeA.end());
		sort(chargeB.begin(), chargeB.end());
		sort(chargeCommon.begin(), chargeCommon.end());
		if (chargeCommon.size())
		{
			// 경우 1. A, B가 같은 충전구역에 겹치고 A는 또 다른 충전구역에 걸쳐 있다면
			if (chargeA.size() > 0 && chargeB.size() == 0)
			{
				maxB = chargeCommon[0].power;
				if (chargeCommon.size() >= 2 && chargeCommon[1].power > chargeA[0].power)
					maxA = chargeCommon[1].power;
				else
					maxA = chargeA[0].power;

			}
			// 경우 2. A, B가 같은 충전구역에 겹치고 B는 또 다른 충전구역에 걸쳐 있다면
			else if (chargeB.size() > 0 && chargeA.size() == 0)
			{
				maxA = chargeCommon[0].power;
				if (chargeCommon.size() >= 2 && chargeCommon[1].power > chargeB[0].power)
					maxB = chargeCommon[1].power;
				else
					maxB = chargeB[0].power;

			}
			// 경우 3. A, B가 같은 충전구역에 겹치고 A, B가 서로 다른 충전구역에 걸쳐 있다면
			else if (chargeA.size() > 0 && chargeB.size() > 0)
			{

				int AC = chargeA[0].power + chargeCommon[0].power;
				int BC = chargeB[0].power + chargeCommon[0].power;
				int AB = chargeA[0].power + chargeB[0].power;
				if (AB > AC && AB > BC)
				{
					maxA = chargeA[0].power;
					maxB = chargeB[0].power;
				}
				else if (AC > BC)
				{
					maxA = chargeA[0].power;
					maxB = chargeCommon[0].power;
				}
				else
				{
					maxA = chargeCommon[0].power;
					maxB = chargeB[0].power;
				}
			}
			// 경우 4. A, B 모두 둘 이상 겹친 충전 구역 내에 있다면
			else if (chargeCommon.size() >= 2)
			{
				maxA = chargeCommon[0].power;
				maxB = chargeCommon[1].power;
			}
			// 경우 5. 이 구역 이외에 A, B 모두 겹치는 충전구역이 없다면
			else
			{
				maxA = chargeCommon[0].power / 2;
				maxB = chargeCommon[0].power / 2;
			}
		}
		else
		{
			if(chargeA.size())
				maxA = chargeA[0].power;
			if(chargeB.size())
				maxB = chargeB[0].power;
		}

		power += maxA;
		power += maxB;

		if (currentTime == M)
			break;

		// 다음으로 이동
		userA.y += dy[trackA[currentTime]];
		userA.x += dx[trackA[currentTime]];
		userB.y += dy[trackB[currentTime]];
		userB.x += dx[trackB[currentTime]];
	}
	return power;
}

int main(int argc, char** argv)
{
	// freopen("C:\\Users\\SSAFY\\Downloads\\sample_input (1).txt", "r", stdin);
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> M >> A;
		for (int i = 0; i < M; i++)
		{
			int t; cin >> t;
			trackA.push_back(t);
		}
		for (int i = 0; i < M; i++)
		{
			int t; cin >> t;
			trackB.push_back(t);
		}
		for (int i = 0; i < A; i++)
		{
			node t;
			cin >> t.x >> t.y >> t.range >> t.power;
			t.num = i + 1;
			BC.push_back(t);
		}
		userA = { 1, 1 };
		userB = { 10, 10 };

		cout << '#' << test_case << " " << getTotalPower() << '\n';
		trackA.clear();
		trackB.clear();
		BC.clear();
	}

	return 0;
}