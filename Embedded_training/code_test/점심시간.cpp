#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

struct people {
	int y, x;
	int distToSt1, distToSt2;
};

struct stair {
	int y, x;
	int time;
};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int N, MinT = 21e8;;
vector<people> members;
vector<stair> stairs;
vector<int> st1, st2;

int getDistance(int y1, int x1, int y2, int x2)
{
	int dify = y1 - y2 > 0 ? y1 - y2 : y2 - y1;
	int difx = x1 - x2 > 0 ? x1 - x2 : x2 - x1;
	return dify + difx;
}

void getTimeToStair()
{
	int size = members.size();

	for (int i = 0; i < size; i++)
	{
		members[i].distToSt1 = getDistance(members[i].y, members[i].x, stairs[0].y, stairs[0].x);
		members[i].distToSt2 = getDistance(members[i].y, members[i].x, stairs[1].y, stairs[1].x);
	}
}

int getTotalTime(vector<int> st1, vector<int> st2)
{
	sort(st1.begin(), st1.end());
	sort(st2.begin(), st2.end());
	int tmp1 = 0; int tmp2 = 0;
	int sz1 = st1.size(); int sz2 = st2.size();

	for (int i = 0; i < sz1; i++)
	{
		if (i >= 3)
		{
			if (st1[i] < st1[i - 3] + stairs[0].time)
				st1[i] = st1[i - 3] + stairs[0].time;
		}
	}
	for (int i = 0; i < sz2; i++)
	{
		if (i >= 3)
		{
			if (st2[i] < st2[i - 3] + stairs[1].time)
				st2[i] = st2[i - 3] + stairs[1].time;
		}
	}

	// 두 계단의 총 이동 시간은 각각
	// (마지막 사람이 계단까지 이동 및 대기한 시간) + (계단 자체의 이동 시간)
	if (sz1 > 0)
		tmp1 = st1[sz1 - 1] + stairs[0].time;
	else
		tmp1 = 0;

	if (sz2 > 0)
		tmp2 = st2[sz2 - 1] + stairs[1].time;
	else
		tmp2 = 0;
	return max(tmp1, tmp2);
}

void dfs(int now)
{
	if (now == members.size())
	{
		int t = getTotalTime(st1, st2);
		MinT = min(t, MinT);
		return;
	}

	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			st1.push_back(members[now].distToSt1);
			dfs(now + 1);
			st1.pop_back();
		}
		else if (i == 1)
		{
			st2.push_back(members[now].distToSt2);
			dfs(now + 1);
			st2.pop_back();
		}
	}
}

// 문제 풀이 방향
// 모든 사람들에 대해 각각의 계단으로 향하는 이동 시간을 기록
// dfs를 이용하여 어떤 사람이 어떤 계단으로 이동하는지 모든 경우를 상정
// 한 계단에 3명 이상의 인원이 몰릴 경우 delay 되는 문제를 반영

int main()
{
	// ("C:\\Users\\User\\Downloads\\sample_input (8).txt", "r", stdin);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int t; cin >> t;
				if (t == 1)
					members.push_back({ i, j, 0, 0 });
				else if (t > 1)
					stairs.push_back({ i, j, t });
			}
		}
		getTimeToStair();
		dfs(0);
		
		cout << "#" << test_case << " " << MinT + 1 << "\n";
		members.clear();
		stairs.clear();
		st1.clear(); st2.clear();
		MinT = 21e8;
	}

	return 0;
}