#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

int Q;

vector<list<int>> belts;
vector<int> Prev;
vector<int> Next;

int main()
{
	// freopen("C:\\Users\\SSAFY\\Downloads\\input.txt", "r", stdin);
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int cmd; cin >> cmd;

		if (cmd == 100)
		{
			int n, m; cin >> n >> m;
			belts = vector<list<int>>(n + 1);
			Prev = vector<int>(m + 1, -1);
			Next = vector<int>(m + 1, -1);
			for (int i = 1; i <= m; i++)
			{
				int num; cin >> num;
				if (belts[num].size() > 0)
				{
					Prev[i] = belts[num].back();
					Next[belts[num].back()] = i;
				}
				belts[num].push_back(i);
			}
		}
		else if (cmd == 200)
		{
			int from, to; cin >> from >> to;

			if (!belts[to].empty())
			{
				Next[belts[from].back()] = belts[to].front();
				Prev[belts[to].front()] = belts[from].back();
			}

			belts[to].splice(belts[to].begin(), belts[from]);
			std::cout << belts[to].size() << "\n";
		}
		else if (cmd == 300)
		{
			int from, to; cin >> from >> to;

			int src = -1, dst = -1;
			if (!belts[from].empty())
			{
				src = belts[from].front();
				belts[from].pop_front();
			}
			if (!belts[to].empty())
			{
				dst = belts[to].front();
				belts[to].pop_back();
			}

			if (!belts[from].empty())
				Prev[belts[from].front()] = src;
			if (!belts[to].empty())
				Prev[belts[to].front()] = dst;

			if (dst != -1)
			{
				if (!belts[from].empty())
					Next[dst] = belts[from].front();
				else
					Next[dst] = -1;
				belts[from].push_front(dst);
				Prev[dst] = -1;
			}
			if (src != -1)
			{
				if (!belts[to].empty())
					Next[src] = belts[to].front();
				else
					Next[src] = -1;

				belts[to].push_back(src);
				Prev[src] = -1;
			}
			std::cout << belts[to].size() << "\n";
		}
		else if (cmd == 400)
		{
			int from, to; cin >> from >> to;
			if (belts[from].size() <= 1)
			{
				std::cout << belts[to].size() << "\n";
				continue;
			}
			int length = belts[from].size() / 2;
			auto end = next(belts[from].begin(), length);
			
			if (!belts[to].empty())
			{
				Next[*(next(end, -1))] = belts[to].front();
				Prev[belts[to].front()] = *(next(end, -1));
			}
			else
				Next[*(next(end, -1))] = -1;

			belts[to].splice(belts[to].begin(), belts[from], belts[from].begin(), end);
			Prev[belts[to].front()] = -1;

			std::cout << belts[to].size() << "\n";
		}
		else if (cmd == 500)
		{
			int num; cin >> num;
			int a = Prev[num], b = Next[num];
			std::cout << a + 2 * b << "\n";
		}
		else if (cmd == 600)
		{
			int belt; cin >> belt;
			int a = - 1, b = -1, c = belts[belt].size();

			if (c != 0)
			{
				a = belts[belt].front();
				b = belts[belt].back();
			}
			
			std::cout << a + 2 * b + 3 * c << "\n";
		}
	}

	return 0;
}