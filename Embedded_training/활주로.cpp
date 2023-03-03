#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	int y;
	int x;
};

bool cmp(int left, int right)
{
	return left < right;
}

int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };

int arr[20][20];
vector<int> road[40];
int N, X;

int chk(vector<int> v)
{
	int len = v.size();
	int underCnt = 0;
	int prev = v[0];
	bool upperFlag = false, donwerFlag = false;
	for (int i = 0; i < len; i++)
	{
		if (prev == v[i])
		{
			underCnt++;
			if (donwerFlag && underCnt >= X)
			{
				donwerFlag = false;
				underCnt = 0;
			}
		}
		else
		{
			if (prev - v[i] >= 2 || prev - v[i] <= -2) return 0;
			if (prev > v[i])
			{
				if (donwerFlag)
					return 0;
				donwerFlag = true;
			}
			else
			{
				if (underCnt < X)
					return 0;
			}
			underCnt = 1;
			prev = v[i];
		}
	}
	if (donwerFlag)
		return 0;
	else
		return 1;
}


int main()
{
	// freopen("C:\\Users\\SSAFY\\Downloads\\sample_input (2).txt", "r", stdin);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N >> X;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
				road[i].push_back(arr[i][j]);
				road[N + j].push_back(arr[i][j]);
			}
		}
		int cnt = 0;
		for (int i = 0; i < 2 * N; i++)
		{
			cnt += chk(road[i]);
		}
		cout << "#" << test_case << " " << cnt << "\n";
		for (int i = 0; i < 2 * N; i++)
		{
			road[i].clear();
		}
	}

	return 0;
}