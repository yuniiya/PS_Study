#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

using namespace std;

int a, b, c, Max, ans;
int arr[102];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c;

	for (int i = 0; i < 3; i++)
	{
		int n, m;
		cin >> n >> m;

		Max = max(Max, m);

		for (int i = n; i < m; i++)
		{
			arr[i]++;
		}
	}

	for (int i = 1; i < Max; i++)
	{
		if (arr[i] == 0)
			continue;

		if (arr[i] == 1)
		{
			ans += arr[i] * a;
		}
		else if (arr[i] == 2)
		{
			ans += arr[i] * b;
		}
		else if (arr[i] == 3)
		{
			ans += arr[i] * c;
		}
	}

	cout << ans;
}