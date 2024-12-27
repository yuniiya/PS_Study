#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

string s;
vector<pair<int, int>> sticks;
vector<int> lasers;
int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// ()의 위치
	cin >> s;

	stack<int> st;
	vector<int> idx;

	for (int i = 0; i < (int)s.size(); i++)
	{
		if (i + 1 <= s.size() - 1 && s[i] == '(' && s[i + 1] == ')')
		{
			lasers.push_back(i);
			i++;

			continue;
		}

		if (st.empty() || s[i] == '(')
		{
			st.push(s[i]);
			idx.push_back(i);
		}
		else if (s[i] == ')')
		{
			sticks.push_back({ idx.back(), i });
			st.pop();
			idx.pop_back();
		}
	}

	int ans = (int)sticks.size();

	for (pair<int, int> stick : sticks)
	{
		for (int laser : lasers)
		{
			if (stick.first < laser && stick.second > laser + 1)
			{
				ans++;
			}
		}
	}

	cout << ans;
}