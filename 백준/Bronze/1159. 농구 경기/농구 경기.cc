#include <iostream>

using namespace std;
int Alpha[26];
int main()
{
	string Ans;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		char a = s[0];

		Alpha[a - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (Alpha[i] >= 5)
			Ans += i + 'a';
	}

	if (Ans.empty())
	{
		cout << "PREDAJA" << "\n";
	}
	else
	{
		cout << Ans << "\n";
	}
}