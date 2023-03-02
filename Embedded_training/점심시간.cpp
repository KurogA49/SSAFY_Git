#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

struct people {
	int y;
	int x;
	int distToSt1, distToSt2;
};

struct stair {
	int y, x;
	int time;
};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };


vector<people> v;
vector<stair> s;
vector<int> p1, p2;
int arr[10][10];
int dat[11];
int N, MinT = 21e8;

int getDistance(int y1, int x1, int y2, int x2)
{
	int dify = y1 - y2 > 0 ? y1 - y2 : y2 - y1;
	int difx = x1 - x2 > 0 ? x1 - x2 : x2 - x1;

	return dify + difx;
}

// 모든 인원들에 대해 두 계단으로 향하는 시간을 각각 기록
void solve()
{
	for (int i = 0; i < 2; i++)
	{
		stair snow = s[i];
		int size = v.size();
		for (int j = 0; j < size; j++)
		{
			people pnow = v[j];
			if (i == 0)
			{
				v[j].distToSt1 = getDistance(pnow.y, pnow.x, snow.y, snow.x);
			}
			else if (i == 1)
			{
				v[j].distToSt2 = getDistance(pnow.y, pnow.x, snow.y, snow.x);
			}
		}
	}
}


int getMinTime(vector<int> st1, vector<int> st2)
{
	// 두 계단 벡터를 입력받기
	// 계단 벡터의 내용은 각각의 인원이 그 계단으로 향하는 시간
	int sz1 = st1.size();
	int sz2 = st2.size();
	int tmp1 = 0, tmp2 = 0;
	// 시간이 작은 순서대로 정렬
	sort(st1.begin(), st1.end());
	sort(st2.begin(), st2.end());

	// 두 계단에 대해,
	for (int i = 0; i < sz1; i++)
	{
		// 현재 몰려 있는 인원이 3명 이상이라면
		if (i >= 3)
		{
			// 그리고 i번째 사람이 계단으로 향하는 시간보다 
			if (st1[i - 3] + s[0].time > st1[i]) {
				st1[i] = st1[i - 3] + s[0].time;
			}
		}
	}

	for (int i = 0; i < sz2; i++)
	{
		if (i >= 3)
		{
			if (st2[i - 3] + s[0].time > st2[i]) {
				st2[i] = st2[i - 3] + s[0].time;
			}
		}
	}

	if (sz1 != 0)
		tmp1 = st1[sz1 - 1] + s[0].time;
	else
		tmp1 = 0;

	if (sz2 != 0)
		tmp2 = st2[sz2 - 1] + s[1].time;
	else
		tmp2 = 0;

	return max(tmp1, tmp2);
}

// dfs 탐색
void dfs(int now)
{
	// 모든 인원을 두 계단에 배정했다면
	if (now == v.size())
	{
		// 이 경우에 대한 최소 소요 시간을 계산
		int result = getMinTime(p1, p2);
		// 만약 현재 최소 시간보다 더 적다면 갱신
		MinT = min(MinT, result);
		return;
	}
	people pnow = v[now];
	// 현재 pnow 사람이 계단 1 혹은 2로 향하는 두 경우를 선정
	// 각각의 계단 벡터에 이동 소요 시간을 등록 및 다음 dfs
	for (int i = 0; i < 2; i++)
	{
		if (i == 1)
		{
			p2.push_back(pnow.distToSt2);
			dat[now]++;
			dfs(now + 1);
			dat[now]--;
			p2.pop_back();
			
		}
		else if (i == 0)
		{
			p1.push_back(pnow.distToSt1);
			dfs(now + 1);
			p1.pop_back();
		}
	}
}

int main()
{
	// freopen("C:\\Users\\SSAFY\\Downloads\\sample_input (8).txt", "r", stdin);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
				// 사람이면 사람 벡터에
				// 계단이면 계단 벡터에 등록
				if (arr[i][j] == 1)
					v.push_back({ i, j, 0, 0 });
				else if (arr[i][j] != 0)
					s.push_back({ i, j, arr[i][j] });
			}
		}
		solve();
		dfs(0);
		cout << "#" << test_case << " " << MinT + 1 << "\n";
	}

	return 0;
}