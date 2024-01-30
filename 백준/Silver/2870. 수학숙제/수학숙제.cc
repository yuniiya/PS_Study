#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n;
string s;
vector<string> v;

bool cmp(string a, string b)
{
	if (a.size() != b.size())
		return a.size() < b.size();

	return a < b;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s;

		string ss = "";
		
		for (int j = 0; j < s.size(); j++)
		{
			if ('0' > s[j] || s[j] > '9')
			{
				if (ss != "")
				{
					v.push_back(ss);
					ss = "";
				}

				continue;
			}

			if ('0' <= s[j] && s[j] <= '9')
			{
				ss += s[j];
			}

			if (ss.front() == '0' && ss.size() > 1)
			{
				ss.erase(ss.begin());
			}
		}

		if (ss != "")
		{
			v.push_back(ss);
		}
	}

	sort(v.begin(), v.end(), cmp);

	for (auto a: v)
	{
		cout << a << "\n";
	}
}