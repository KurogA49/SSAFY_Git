#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int** arr;
int* used;
vector<int> v;

int check(int** arr, int D, int W, int K)
{
	vector<int> tmp;
	for (int i = 0; i < W; i++)
	{
		bool flag = false;
		for (int j = 0; j < D; j++)
		{
			// 검사 배열에 들어올 특성이 전과 다를 때
			if (tmp.size() > 0 && tmp.back() != arr[j][i])
			{
				// 적층된 성분의 두께가 K보다 크다면 해당 검사는 통과
				if (tmp.size() >= K)
				{
					tmp.clear();
					flag = true;
					break;
				}
				else
				{
					tmp.clear();
				}
			}
			tmp.push_back(arr[j][i]);
		}
		if (tmp.size() < K)
			return 0;
		tmp.clear();
	}
	return 1;
}

int rebuild(int D, int W, int K, int cnt)
{
	if (cnt == D)
	{
		return cnt;
	}
	for (int i = 0; i < D; i++)
	{
		// 보수작업 전 복구할 임시배열
		int* tmp = new int[W];
		for (int j = 0; j < W; j++)
		{
			tmp[j] = arr[i][j];
		}

		// 보수 작업 - 모두 1로
		for (int j = 0; j < W; j++)
		{
			arr[i][j] = '1';
		}
		if (check(arr, D, W, K) == 1)
		{
			v.push_back(cnt - 1);
			return cnt;
		}
			
		// 재귀
		rebuild(D, W, K, cnt + 1);
		// 보수 작업 - 모두 0으로
		for (int j = 0; j < W; j++)
		{
			arr[i][j] = '0';
		}
		if (check(arr, D, W, K) == 1)
		{
			return cnt;
			v.push_back(cnt - 1);
		}
			
		rebuild(D, W, K, cnt + 1);
		// 복구
		for (int j = 0; j < W; j++)
		{
			arr[i][j] = tmp[j];
		}
	}

	return 0;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		// 사이즈 및 기준 입력
		int D, W, K, cnt = 0;
		cin >> D >> W >> K;
		// 필름 보호막 생성 및 값 입력
		arr = new int* [D];
		for (int i = 0; i < D; i++)
		{
			arr[i] = new int[W] {};
			for (int j = 0; j < W; j++)
			{
				cin >> arr[i][j];
			}
		}

		// 초기검사
		if (check(arr, D, W, K) == 0)
		{
			// 초기검사가 불량이라면 보수작업 진행
			cnt = rebuild(D, W, K, cnt);
		}
		else
			v.push_back(0);
		sort(v.begin(), v.end());
		cout << '#' << T << " " << v.front();

		// 작업 종료
		v.clear();
		for (int i = 0; i < D; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}

	return 0;
}