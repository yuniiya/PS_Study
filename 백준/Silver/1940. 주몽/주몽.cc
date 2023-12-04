#include <iostream>

using namespace std;
int n, m;
int Cnt;
int M[15004];
int main()
{
	// 번호 2개 합이 M이 되는 경우
	cin >> n;
	cin >> m;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		M[i] = a;
	}

	for (int i = 0; i < n; i++)
	{
		if (M[i] == 0)
			continue;

		for (int j = i + 1; j < n; j++)
		{
			if (M[j] == 0)
				continue;

			if (M[i] + M[j] == m)
			{
				Cnt++;

				M[i] = 0;
				M[j] = 0;

				break;
			}
		}
	}

	cout << Cnt << endl;
}
