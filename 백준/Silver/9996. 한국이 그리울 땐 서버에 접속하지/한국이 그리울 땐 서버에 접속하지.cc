#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

using namespace std;

int n;
string s,ss;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;

	int idx = s.find('*');
	string prefix = s.substr(0, idx);
	string suffix = s.substr(idx + 1);

	for (int i = 0; i < n; i++)
	{
		cin >> ss;
		
		if ((int)ss.size() >= (int)prefix.size() + (int)suffix.size())
		{
			if(prefix == ss.substr(0, idx) && suffix == ss.substr((int)ss.size() - (int)suffix.size()))
			{
				cout << "DA" << "\n";
				continue;
			}
		}

		cout << "NE" << "\n";
	}

	return 0;
}
