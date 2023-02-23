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
	int range;
	int power;
	int num;
};
struct p {
	int y;
	int x;
};

int dy[5] = { 0, -1, 0, 1, 0 };
int dx[5] = { 0, 0, 1, 0, -1 };

int N, K;
string pwds;

int hexToInt(string hex)
{
	int sum = 0;
	int cnt = 0;
	for (int i = hex.length() - 1; i >= 0; i--)
	{
		int tmp;
		if (hex[i] >= 'A')
			tmp = 10 + hex[i] - 'A';
		else
			tmp = hex[i] - '0';
			
		tmp = tmp << (4 * cnt);
		sum += tmp;
		cnt++;
	}

	return sum;
}

bool cmp(int left, int right)
{
	return left > right;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N >> K;
		cin >> pwds;
		pwds += pwds;
		int window = N / 4;
		unordered_map<int, int> windows;
		
		for (int i = 0; i <= pwds.length() - window; i++)
		{
			int gap = hexToInt(pwds.substr(i, window));
			windows[gap]++;
		}
		vector<int> arr;
		for (auto i = windows.begin(); i != windows.end(); i++)
		{
			arr.push_back(i->first);
		}
		sort(arr.begin(), arr.end(), cmp);
		cout << "#" << test_case << " " << arr[K - 1] << "\n";
	}

	return 0;
}