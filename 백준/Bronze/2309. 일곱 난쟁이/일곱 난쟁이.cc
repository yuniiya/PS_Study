#include <iostream>
#include <algorithm>

using namespace std;
int N[9];
int Sum;
pair<int, int> P;
void Select()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (Sum - N[i] - N[j] == 100)
			{
				P = { i, j };
				return;
			}
		}
	}
}

int main()
{

	for (int i = 0; i < 9; i++)
	{
		cin >> N[i]; 
		Sum += N[i];
	}

	sort(N, N + 9);
	Select();

	for (int i = 0; i < 9; i++)
	{
		if (i == P.first || i == P.second)
			continue;

		cout << N[i] << "\n";
	}
}