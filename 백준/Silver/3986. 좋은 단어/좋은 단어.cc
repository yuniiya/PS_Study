#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

int n, ans;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		stack<char> st;
		cin >> s;

		for (char c : s)
		{
			if (st.empty())
			{
				st.push(c);
			}
			else
			{
				if (st.top() == c)
				{
					st.pop();
				}
				else
				{
					st.push(c);
				}
			}
		}

		if (st.empty())
			ans++;
	}

	cout << ans;
}