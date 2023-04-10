#include<iostream>
#include <cstring>
using namespace std;

int arr[20][20];
int Copy[20][20];
int D, W, K, injectioncnt;
int ans = 21e8;

int check()
{
	// 세로 방향으로 K개 이상 연결된 A 또는 B가 모든 열에 있는가?
	for (int i = 0; i < W; i++)
	{
		// 가장 위에 있는 성분
		int base = Copy[0][i];
		int cnt = 0;
		int flag = 0;
		for (int j = 0; j < D; j++)
		{
			if (base == Copy[j][i])
			{
					cnt++;
				if (cnt >= K)
				{
					flag = 1;
					break;
				}
			}
			else
			{
				base = Copy[j][i];
				cnt = 1;
			}
		}
		if (flag == 0)
			return 0;
	}
	return 1;
}

void rebuild(int lev)
{
	// 기저조건 -> D번 행까지 도달했을 때
	if (lev == D)
	{
		// 성능테스트
		if (check()) {
			if (injectioncnt < ans)
				ans = injectioncnt;
		}
		return;
	}

	// bactracking -> 현재 투입한 약품 횟수가 ans보다 많으면 
	// 이 작업은 쓸모없으므로 돌아가기
	if (ans < injectioncnt)
		return;

	// 일단 아무것도 안 하기
	// 재귀
	rebuild(lev + 1);

	injectioncnt++;
	// 보수 작업 - 모두 1로
	for (int j = 0; j < W; j++)
		Copy[lev][j] = 1;
	// 재귀
	rebuild(lev + 1);
	// 복구
	for (int i = 0; i < W; i++)
		Copy[lev][i] = arr[lev][i];
	injectioncnt--;


	injectioncnt++;
	// 보수 작업 - 모두 0으로
	for (int j = 0; j < W; j++)
		Copy[lev][j] = 0;
	// 재귀
	rebuild(lev + 1);
	// 복구
	for (int i = 0; i < W; i++)
		Copy[lev][i] = arr[lev][i];
	injectioncnt--;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        ans = 21e8;
		injectioncnt = 0;
		memset(arr, 0, sizeof(arr));
		memset(Copy, 0, sizeof(Copy));

		// 사이즈 및 기준 입력
		cin >> D >> W >> K;
		// 필름 보호막 생성 및 값 입력
		for (int i = 0; i < D; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> arr[i][j];
				Copy[i][j] = arr[i][j];
			}
		}
		// 처음부터 안 넣어도 통과하는 경우
		if (check())
			ans = 0;
		else
			rebuild(0); // 보수작업 실행
		
		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;
}