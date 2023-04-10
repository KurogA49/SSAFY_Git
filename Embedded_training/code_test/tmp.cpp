#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include<algorithm>
using namespace std;


struct uglynum {
	int two;
	int thr;
	int fiv;
};
priority_queue<uglynum> pq;
bool operator < (uglynum left, uglynum right)
{
	int leftn = pow(2, left.two) + pow(3, left.thr) + pow(5, left.fiv);
	int rightn = pow(2, right.two) + pow(3, right.thr) + pow(5, right.fiv);

	return leftn < rightn;
}

int main()
{
	int N;
	cin >> N;
	
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			for (int k = 0; k < 100; k++)
			{
				pq.push(uglynum{ i, j, k });
			}
		}
	}
	vector<int> order;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		order.push_back(t);
	}


    return 0;
}
