#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>
#include <map>
#include <unordered_map>

using namespace std;

int N[1000002][2];
int n, a;
stack<int> st;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(N, -1, sizeof(N));
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		N[i][0] = a;
		
		while (st.size() > 0 && a > N[st.top()][0])
		{
			int t = st.top();
			if (a > N[t][0])
			{
				N[t][1] = a;
				st.pop();
			}
		}

		if (i > 0)
		{
			if (N[i - 1][1] == -1 && a > N[i - 1][0])
			{
				N[i - 1][1] = a;
			}
			else
			{
				st.push(i - 1);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << N[i][1] << " ";
	}

	return 0;
}