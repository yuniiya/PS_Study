#include <iostream>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	int end = s.size() - 1;

	for (int i = 0; i < s.size() / 2; i++)
	{
		if (s[i] != s[end])
		{
			cout << 0 << "\n";
			exit(0);
		}

		end--;
	}

	cout << 1 << "\n";
}