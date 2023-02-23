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

struct bucket {
	int y;
	int x;
	int endx;
	int best;

	bool operator < (bucket right) const
	{
		return best < right.best;
	}
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

// N*N 모양의 벌통
// 각 칸에 담긴 꿀의 양을 숫자로 표기
// 두 명의 일꾼이 가로로 된 크기 M짜리 벌통을 이용하여 꿀을 채취
// 단, 두 벌통이 겹치는 경우는 없다
// 그리고 한 사람 당 제한량 C 보다 크게 채취하는 것 또한 불가능하다
// 각각 채취한 1칸씩의 꿀을 제곱하여 모두 합한 값이 꿀의 판매액이라고 하면
// 그 최대는?

int arr[10][10];
int N, M, C;

int getMaxHoney(vector<int> tmp)
{
	int sum = 0;
	int gop = 0;
	for (int i = 0; i < tmp.size(); i++)
	{
		sum += tmp[i];
		gop += tmp[i] * tmp[i];
	}
	if (sum > C)
		return -1;
	else
		return gop;
}

int maxA;
int datA[5];
vector<int> arq;
void dfs(vector<int> bkts)
{
	if (arq.size() > 0)
	{
		int t = getMaxHoney(arq);
		if (maxA < t)
			maxA = t;
	}

	if (arq.size() == bkts.size())
		return;

	for (int i = 0; i < bkts.size(); i++)
	{
		if (datA[i] == 0)
		{
			datA[i]++;
			arq.push_back(bkts[i]);
			dfs(bkts);
			arq.pop_back();
			datA[i]--;
		}
	}

}

int main(int argc, char** argv)
{
	//freopen("C:\\Users\\SSAFY\\Downloads\\sample_input (4).txt", "r", stdin);
	int test_case;
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		priority_queue<bucket> pq;
		cin >> N >> M >> C;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j <= N - M; j++)
			{
				vector<int> tpt;
				for (int k = j; k < j + M; k++)
				{
					tpt.push_back(arr[i][k]);
				}
				bucket tmp;
				tmp.y = i; tmp.x = j; tmp.endx = j + M;

				maxA = 0;
				arq.clear();
				dfs(tpt);
				tmp.best = maxA;
				pq.push(tmp);
			}
		}
		bucket A, B;
		A = pq.top(); pq.pop();
		B = A;
		while (!pq.empty())
		{
			bucket tmp = pq.top(); pq.pop();
			if (A.y == tmp.y && (tmp.x >= A.x && tmp.x <= A.endx)) continue;
			if (A.y == tmp.y && (tmp.endx >= A.x && tmp.endx <= A.endx)) continue;
			B = tmp;
			break;
		}
		if (B.y == A.y && B.x == A.x)
			cout << "#" << test_case << " " << A.best << "\n";
		else
			cout << "#" << test_case << " " << A.best + B.best << "\n";

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				arr[i][j] = 0;
			}
		}
	}

	return 0;
}