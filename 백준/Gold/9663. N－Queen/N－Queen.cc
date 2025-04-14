#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

using namespace std;

int n, cnt;
bool issued1[30], issued2[30], issued3[30];
void func(int cur)
{
	if (cur == n)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (issued1[i] || issued2[cur + i] || issued3[cur - i + n - 1])
			continue;

		issued1[i] = true;
		issued2[cur + i] = true;
		issued3[cur - i + n - 1] = true;
		func(cur + 1);
		issued1[i] = false;
		issued2[cur + i] = false;
		issued3[cur - i + n - 1] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n;

	func(0);
	cout << cnt;
}