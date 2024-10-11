#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <stack>

using namespace std;

int n, t;
int cnt = 1;
string ans;
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> st;

	cin >> n;

	while (n--)
	{
		cin >> t;

		while (cnt <= t)
		{
			st.push(cnt++);
			ans += "+\n";
		}

		if (st.top() != t)
		{
			cout << "NO";
			return 0;
		}

		st.pop();
		ans += "-\n";
	}

	cout << ans;
}