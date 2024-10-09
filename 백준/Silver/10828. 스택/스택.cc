#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <stack>

using namespace std;

int main(void) 
{
	stack<int> st;
	
	int a;
	cin >> a;

	for (int i = 0; i < a; i++)
	{
		string s;
		cin >> s;

		if (s == "push")
		{
			int i;
			cin >> i;

			st.push(i);
		}
		else if (s == "pop")
		{
			if (!st.empty())
			{
				cout << st.top() << '\n';
				st.pop();
			}
			else
			{
				cout << -1 << '\n';
			}
		}
		else if (s == "size")
		{
			cout << st.size() << '\n';
		}
		else if (s == "empty")
		{
			cout << st.empty() << '\n';
		}
		else if (s == "top")
		{
			if (!st.empty())
				cout << st.top() << '\n';
			else
				cout << -1 << '\n';
		}
	}
}