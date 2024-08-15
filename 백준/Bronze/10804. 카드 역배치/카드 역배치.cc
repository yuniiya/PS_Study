#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N[21];
int a, b;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 20; i++)
	{
		N[i] = i;
	}

	for (int i = 0; i < 10; i++)
	{
		cin >> a >> b;
	
		int tmp = b;

		for (int j = a; j <= a + ((b - a) / 2); j++)
		{
			swap(N[j], N[tmp--]);
		}
	}

	for (int i = 1; i <= 20; i++)
	{
		cout << N[i] << ' ';
	}
}