#include <iostream>
#include <algorithm>

using namespace std;

long long a, b;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;

	if (a == b)
	{
		cout << 0;
	}
	else
	{
		if (a > b)
		{
			swap(a, b);
		}

		cout << b - a - 1 << '\n';

		for (long long i = a + 1; i < b; i++)
		{
			cout << i << ' ';
		}
	}
}