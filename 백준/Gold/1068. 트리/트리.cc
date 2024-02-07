#include <iostream>
#include <vector>

using namespace std;
int n, m, k, Ans;
int Root;
vector<int> N[54];

int dfs(int here)
{
	int Ret = 0;
	int Child = 0;

	for (int there : N[here])
	{
		if (there == k)
			continue;

		Ret += dfs(there);
		Child++;
	}

	if (Child == 0)
		return 1;

	return Ret;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> m;

		if (m == -1)
			Root = i;
		else
			N[m].push_back(i);
	}

	cin >> k;

	if (k == Root)
		cout << Ans << "\n";
	else
		cout << dfs(Root) << "\n";
}