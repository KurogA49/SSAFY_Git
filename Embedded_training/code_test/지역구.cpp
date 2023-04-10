#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include<algorithm>
using namespace std;

struct node {
	int y;
	int x;
};

struct edge {
	int fy, fx;
	int ty, tx;
	int cost;
};

struct village {
	int num;
	int gross;
};

int parent[8];
int dat[8];
int N, Min = 21e8;
vector<village> city;
vector<village> areaA, areaB;

int Find(int n)
{
	if (parent[n] == n)
		return n;
	parent[n] = Find(parent[n]);
	return parent[n];
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb) return;
	parent[pb] = pa;
}

void dfs(int lev)
{
	// 현재 구성된 지역구 A를 통해 지역구 B를 만들기
	for (int i = 0; i < city.size(); i++)
	{
		bool flag = true;
		for (int j = 0; j < areaA.size(); j++)
		{
			if (areaA[j].num == city[i].num)
				flag = false;
		}
		if(flag)
			areaB.push_back(city[i]);
	}

	// 지역구 검사 - 두 지역구 내의 마을들이 서로 연결되어 있는가?


	// 조건에 부합한다면 각 지역구 유권자 총합의 차이를 파악
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < areaA.size(); i++)
	{
		sum1 += areaA[i].gross;
	}
	for (int i = 0; i < areaB.size(); i++)
	{
		sum2 += areaB[i].gross;
	}
	int diff = sum1 - sum2 > 0 ? sum1 - sum2 : sum2 - sum1;
	if (diff < Min)
		Min = diff;
	areaB.clear();

	// 조합 가능한 최대의 경우는 N-1개의 마을과 나머지 하나의 마을
	if (lev == N - 1)
		return;

	for (int i = 0; i < city.size(); i++)
	{
		// 이미 추가한 마을이 아니면
		if (dat[i] == 0)
		{
			dat[city[i].num]++;
			areaA.push_back(city[i]);
			dfs(lev + 1);
			areaA.pop_back();
			dat[city[i].num]--;
		}
	}
}

int main()
{
	int T; cin >> T;
	for (int test_case = 0; test_case < T; test_case++)
	{
		int min = 21e8;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			parent[i] = i;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int chk; cin >> chk;
				if (chk == 1)
				{
					Union(i, j);
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			int gross; cin >> gross;
			city.push_back({ i, gross });
		}
		dat[0]++;
		areaA.push_back(city[0]);
		dfs(1);

		areaA.clear();
		areaB.clear();
		city.clear();
		for (int i = 0; i < N; i++)
		{
			dat[i] = 0;
		}
		Min = 21e8;
	}
	

	return 0;
}