#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

using namespace std;

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a;
	cin >> a;

	while (a--)
	{
		string s;
		cin >> s;

		list<char> L;
		list<char>::iterator cursor = L.begin();

		for (char c : s)
		{
			if (c == '<')
			{
				if (cursor != L.begin())
				{
					cursor--;
				}
			}
			else if (c == '>')
			{
				if(cursor != L.end())
				{
					cursor++;
				}
			}
			else if (c == '-')
			{
				if (cursor != L.begin())
				{
					cursor--;
					cursor = L.erase(cursor);
				}
			}
			else
			{
				L.insert(cursor, c);

			}
		}

		for (char c : L)
		{
			cout << c;
		}

		cout << '\n';
	}
}