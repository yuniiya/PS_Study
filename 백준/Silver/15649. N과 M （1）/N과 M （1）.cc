#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

using namespace std;

int n, m;
bool check[9];
int arr[9];

void func(int k)
{
	if(k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			arr[k] = i;
			func(k + 1);
			check[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	func(0);
}