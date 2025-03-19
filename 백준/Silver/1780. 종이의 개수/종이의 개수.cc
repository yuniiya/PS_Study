#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

using namespace std;

int n;
int paper[2200][2200];
int cnt[3];

bool check(int x, int y, int len)
{
	for (int i = x; i < x + len; i++)
	{
		for (int j = y; j < y + len; j++)
		{
			if (paper[x][y] != paper[i][j])
				return false;
		}
	}

	return true;
}

void func(int x, int y, int len)
{
	if(check(x, y, len))
	{
		cnt[paper[x][y] + 1]++;
		return;
	}

	int size = len / 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			func(x + i * size, y + j * size, size);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> paper[i][j];
		}
	}

	func(0, 0, n);

	for (int i : cnt)
	{
		cout << i << '\n';
	}
}
