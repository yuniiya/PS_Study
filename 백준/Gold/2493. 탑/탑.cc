#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

int n, a;
int main() 
{
	stack<pair<int, int>> st;
	stack<pair<int, int>> tmp;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		st.push(make_pair(a, i + 1));
	}

	vector<int> ans(n, 0);

	while (!st.empty())
	{
		tmp.push(st.top());
		st.pop();

		if (st.empty())
		{
			break;
		}

		while (!tmp.empty() && tmp.top().first < st.top().first)
		{
			ans[tmp.top().second - 1] = st.top().second;
			tmp.pop();

		}
	}

	for (int i : ans)
	{
		cout << i << ' ';
	}
}