#include <iostream>
#include <stack>

using namespace std;

string s;
int main()
{
	while (getline(cin, s))
	{
		if (s == ".")
			break;
	
		stack<char> st;

		for (int i = 0; i < s.size(); i++)
		{
			if (!st.empty())
			{
				if ((st.top() == '(' && s[i] == ')') || (st.top() == '[' && s[i] == ']'))
				{
					st.pop();
					continue;
				}
			}

			if (s[i] == '(' || s[i] == '[' || s[i] == ')' || s[i] == ']')
				st.push(s[i]);
		}
	
		if (st.empty())
			cout << "yes\n";
		else
			cout << "no\n";
	}
}