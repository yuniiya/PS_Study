#include <iostream>
#include <algorithm>

using namespace std;

int N[10];
int ans = -1;
int main(void)
{
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		N[s[i] - '0']++;
	}

	for (int i = 0; i < 10; i++)
	{
		if (i != 6 && i != 9) 
		{
			ans = max(ans, N[i]);
		}
	}

	int tmp = (N[6] + N[9] + 1) / 2;
	if (tmp > ans)
	{
		ans = tmp;
	}

	cout << ans;
}