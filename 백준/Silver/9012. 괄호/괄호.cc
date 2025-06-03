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

int n;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		stack<char> st;
		cin >> s;
		
		for (int j = 0; j < s.size(); j++)
		{
			if (st.size())
			{
				if (s[j] == ')' && st.top() == '(')
					st.pop();
				else
					st.push(s[j]);
			}
			else
				st.push(s[j]);
		}

		if (st.size())
			cout << "NO" << "\n";
		else
			cout << "YES" << "\n";
	}

	return 0;
}