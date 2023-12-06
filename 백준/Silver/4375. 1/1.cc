#include <iostream>

using namespace std;
int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> n)
	{
		long long Num = 1;
		int Cnt = 1;

		while (Num % n != 0)
		{
			Num = (Num * 10) + 1;
			Num %= n;

			Cnt++;
		}

		cout << Cnt << '\n';
	}

	return 0;
}