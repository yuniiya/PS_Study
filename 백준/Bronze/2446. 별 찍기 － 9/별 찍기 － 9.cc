#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a;
	cin >> a;

	for (int i = 0; i < a - 1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << ' ';
		}

		for (int j = 0; j < (a - i) * 2 - 1; j++)
		{
			cout << '*';
		}

		cout << "\n";
	}
	
	for (int i = a - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			cout << ' ';
		}
		for (int j = 0; j < (a - i) * 2 - 1; j++)
		{
			cout << '*';
		}

		cout << "\n";
	}
}	