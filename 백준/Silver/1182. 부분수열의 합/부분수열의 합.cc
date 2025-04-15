#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

using namespace std;

int n, s, cnt;
int arr[24];

void func(int depth, int sum)
{
	if (depth == n)
	{
		if (sum == s)
		{
			cnt++;
		}
		return;
	}

	func(depth + 1, sum);
	func(depth + 1, arr[depth] + sum);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	func(0, 0);
	
	if (s == 0)	cnt--;

	cout << cnt;
}