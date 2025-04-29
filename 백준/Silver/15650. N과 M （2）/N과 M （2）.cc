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
vector<int> v;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		if (i < m)
		{
			v.push_back(0);
		}
		else
		{
			v.push_back(1);
		}
	}

	do
	{
		for (int i = 0; i < n; i++)
		{
			if (v[i] == 0)
			{
				cout << i + 1 << ' ';
			}
		}
		cout << '\n';

	} while (next_permutation(v.begin(), v.end()));

}