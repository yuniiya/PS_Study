#include <iostream>
#include <stack>

using namespace std;

int n;
string s;
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s;

		stack<char> st;
		for (int j = 0; j < s.size(); j++)
		{
			if (!st.empty())
			{
				if (st.top() == '(' && s[j] == ')')
				{
					st.pop();
					continue;
				}
			}

			st.push(s[j]);
		}

		if (st.empty())
		{
			cout << "YES" "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}
}