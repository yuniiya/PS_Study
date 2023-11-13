#include <iostream>

using namespace std;

const int MAX_SIZE = 11;
int main()
{
	int n;
	cin >> n;

	int Results[MAX_SIZE]{};

	for (int i = 1; i <= n; i++)
	{
		int Count;
		cin >> Count;

		for (int j = 0; j < n; j++)
		{
			if (Results[j] == 0 && Count == 0)
			{
				Results[j] = i;
				break;
			}
			else if (Results[j] == 0)
			{
				Count--;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << Results[i] << ' ';
	}
}