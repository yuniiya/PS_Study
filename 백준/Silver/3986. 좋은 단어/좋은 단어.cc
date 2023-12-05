#include <iostream>
#include <string>
#include <stack>

using namespace std;
string s;
int n;
int Cnt;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;

		stack<int> ST;
		int j = (int)s.size() - 1;

		while (j >= 0)
		{
			if (ST.size() && ST.top() == s[j])
			{
				ST.pop();
			}
			else
			{
				ST.push(s[j]);
			}

			j--;
		}

		if (ST.empty())
			Cnt++;
	}

	cout << Cnt;
}
