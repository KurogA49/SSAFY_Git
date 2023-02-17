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

struct stocks {
	int stockNum;
	int cost;
	bool operator < (stocks right) const
	{
		return cost < right.cost;
	}
};

// 초기투자액, 월 투자액, 기간, 종목 수
int Ms, Ma, L, N, Now;
int stockData[15][16];
int takingStocks[15];
int stockPrice[15];
int tmpStocks1[15];
int tmpStocks2[15];
priority_queue<stocks> pq;
priority_queue<stocks> qq;

int main()
{
	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++)
	{
		cin >> Ms >> Ma >> N >> L;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j <= L; j++)
			{
				cin >> stockData[i][j];
			}
		}
		Now = Ms;
		// 주식 구매 과정
		// 0월부터 N월까지,
		for (int i = 0; i <= L; i++)
		{
			// 1월차 이후부터 Ma만큼의 투자액 공급
			if (i >= 1)
				Now += Ma;
			// 현재 보유한 주식이 존재한다 = 지난달에 구매한 주식이므로
			// 현재 시세에 맞추어 매도
			for (int j = 0; j < N; j++)
			{
				Now += takingStocks[j] * stockData[j][i];
				takingStocks[j] = 0;
			}
			// 마지막 달일 경우 주식 구매가 불가능하니 break
			if (i == L)
				break;

			// 각각의 주식 종목의 시가를 파악
			// (다음달 시세) - (이번달 시세)
			// 단순 시세차익 순서를 따르는 큐
			// 시세차익에 현재 구매가능한 주식 수를 곱한 최대 실현 이익 큐
			for (int j = 0; j < N; j++)
			{
				int diff = stockData[j][i + 1] - stockData[j][i];
				int able = Now / stockData[j][i];
				qq.push({ j, diff });
				pq.push({ j, able * diff });
			}

			// 시뮬레이션 #1
			// 시세차익 순서대로 얻는 이익을 계산
			int tNow1 = Now, tNow2 = Now;
			int sum1 = 0, sum2 = 0;
			while (!qq.empty())
			{
				int num = qq.top().stockNum;
				if (qq.top().cost > 0 && Now >= stockData[num][i])
				{
					tmpStocks1[num] = tNow1 / stockData[num][i];
					sum1 += tmpStocks1[num] * (stockData[num][i + 1] - stockData[num][i]);
					tNow1 %= stockData[num][i];
				}
				qq.pop();
			}

			// 시뮬레이션 #2
			// 최대실현이익 순서대로 얻는 이익을 계산
			while (!pq.empty())
			{
				int num = pq.top().stockNum;
				if (pq.top().cost > 0 && Now >= stockData[num][i])
				{
					tmpStocks2[num] = tNow2 / stockData[num][i];
					sum2 += tmpStocks2[num] * (stockData[num][i + 1] - stockData[num][i]);
					tNow2 %= stockData[num][i];
				}
				pq.pop();
			}
			// 두 시뮬레이션을 통해 얻은 계산값으로
			// 가장 많은 이익을 거둔 시나리오를 선택 
			for (int i = 0; i < 15; i++)
			{
				if (sum1 > sum2)
					takingStocks[i] = tmpStocks1[i];
				else
					takingStocks[i] = tmpStocks2[i];
				tmpStocks1[i] = 0;
				tmpStocks2[i] = 0;
			}
			if (sum1 > sum2)
				Now = tNow1;
			else
				Now = tNow2;
		}
		// 수익은 초기 투자액과 월별 투자액을 제한 값
		Now = Now - Ms - Ma * L;
		cout << '#' << test_case + 1 << " " << Now << '\n';
	}

	return 0;
}