#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	int y;
	int x;
};

int N, cnt;
vector<int> path;
int dat[51];

void dfs(int sum)
{
	int len = path.size();
	if (len > 1)
	{
		if (path[len - 1] < path[len - 2]) return;
	}
	if (sum == N)
		cnt++;
	if (sum >= N)
		return;

	for (int i = 1; i <= N; i++)
	{
		if (dat[i] >= 2) continue;
		dat[i]++;
		path.push_back(i);
		dfs(sum + i);
		path.pop_back();
		dat[i]--;
	}
}

int main()
{
	cin >> N;
	dfs(0);
	cout << cnt;

	return 0;
}