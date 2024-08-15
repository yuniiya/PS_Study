#include <iostream>
#include <algorithm>

using namespace std;

int sum;
int num = 101;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 7; i++)
	{
		int a;
		cin >> a;

		if (a & 1)
		{
			sum += a;
			num = min(num, a);
		}
	}

	if (sum == 0)
	{
		cout << -1;
	}
	else
	{
		cout << sum << '\n' << num;
	}
}