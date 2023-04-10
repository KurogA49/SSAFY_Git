#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

struct node {
	int y;
	int x;
};

int magnets[4][8];
int path[4];
int K;

void shift(int arr[8], int opt)
{
	if (opt == 1)
	{
		int tmp = arr[7];
		int tarr[8] = {};
		for (int i = 1; i < 8; i++)
		{
			tarr[i] = arr[i - 1];
		}
		tarr[0] = tmp;
		for (int i = 0; i < 8; i++)
		{
			arr[i] = tarr[i];
		}
	}
	else if (opt == -1)
	{
		int tmp = arr[0];
		int tarr[8] = {};
		for (int i = 0; i < 7; i++)
		{
			tarr[i] = arr[i + 1];
		}
		tarr[7] = tmp;
		arr = tarr;
		for (int i = 0; i < 8; i++)
		{
			arr[i] = tarr[i];
		}
	}
}

// 빨간색 화살표가 가리키는 index가 0이라면
// 다른 자석과 연결될 index는 각각 2, 6
void rotate(int num, int direction)
{
	if (num == 0)
	{
		path[num]++;
		if (path[num + 1] == 0 && magnets[num + 1][6] != magnets[num][2])
			rotate(num + 1, 0 - direction);
		shift(magnets[num], direction);
	}
	else if (num == 3)
	{
		path[num]++;
		if (path[num - 1] == 0 && magnets[num - 1][2] != magnets[num][6])
			rotate(num - 1, 0 - direction);
		shift(magnets[num], direction);
	}
	else
	{
		path[num]++;
		if (path[num + 1] == 0 && magnets[num + 1][6] != magnets[num][2])
			rotate(num + 1, 0 - direction);
		if (path[num - 1] == 0 && magnets[num - 1][2] != magnets[num][6])
			rotate(num - 1, 0 - direction);
		shift(magnets[num], direction);
	}
}

int main()
{
	 freopen("C:\\Users\\User\\Downloads\\sample_input (5).txt", "r", stdin);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> K;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cin >> magnets[i][j];
			}
		}
		for (int i = 0; i < K; i++)
		{
			int mag, di;
			cin >> mag >> di;
			rotate(mag - 1, di);
			for (int i = 0; i < 4; i++)
			{
				path[i] = 0;
			}
		}
		int sum = 0;
		for (int i = 0; i < 4; i++)
		{
			if (magnets[i][0] == 1)
				sum += (1 << i);
			
		}
		cout << "#" << test_case << " " << sum << "\n";
	}

	return 0;
}