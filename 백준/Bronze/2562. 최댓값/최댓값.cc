#include <iostream>

using namespace std;

int ans, idx;
int main()
{
	for (int i = 0; i < 9; i++)
	{
		int n;
		cin >> n;

		if (ans < n)
		{
			ans = n;
			idx = i + 1;
		}
	}

	cout << ans << '\n';
	cout << idx << '\n';
}