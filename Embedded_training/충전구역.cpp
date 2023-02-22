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
		// 현재 두 사람이 충전 구역 내에 있는가?
		int maxA = 0;
		int maxB = 0;
		int tmpA = 0;
		int tmpB = 0;
		for (int i = 0; i < BC.size(); i++)
		{
			int fromA = getDistance(userA.y, userA.x, BC[i].y, BC[i].x);
			int fromB = getDistance(userB.y, userB.x, BC[i].y, BC[i].x);
			
			// 혹시 같은 충전 구역 내에 두 사람이 모두 있다면
			// 생각할 수 있는 경우
			// A의 현재 위치가 겹쳐져 있으면 A가 버리고 B에게 몰아주는 경우
			// B의 현재 위치가 겹쳐져 있으면 B가 버리고 A에게 몰아주는 경우
			if (fromA <= BC[i].range && fromB <= BC[i].range)
			{
				if (tmpA < BC[i].power / 2)
					tmpA = BC[i].power / 2;
				if (tmpB < BC[i].power / 2)
					tmpB = BC[i].power / 2;
			}
			// 서로 떨어져 있다면
			else
			{
				if (fromA <= BC[i].range && maxA < BC[i].power)
				{
					maxA = BC[i].power;
				}
					
				if (fromB <= BC[i].range && maxB < BC[i].power)
				{
					maxB = BC[i].power;
				}
					
			}
		}
		if (maxA > tmpA)
		{
			if (maxB < tmpB * 2)
				maxB = tmpB * 2;
		}
		else if (maxB > tmpB)
		{
			if (maxA < tmpA * 2)
				maxA = tmpA * 2;
		}
		else 
		{
			if (maxA < tmpA * 2)
				maxA = tmpA * 2;
			else if (maxB < tmpB * 2)
				maxB = tmpB * 2;
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