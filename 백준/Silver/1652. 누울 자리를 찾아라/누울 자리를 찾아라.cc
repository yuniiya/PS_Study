#include <iostream>

using namespace std;

bool Room[101][101]{};
int n;
int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char a;
			cin >> a;

			// X 체크
			if (a == 'X')
				Room[i][j] = true;
		}
	}

	int CountCol = 0;
	int CountRow = 0;

	for (int i = 0; i < n; i++)
	{
		int TempCol = 0;
		int TempRow = 0;

		// 가로
		for (int j = 0; j < n; j++)
		{
			if (Room[j][i] != true)
			{
				TempRow++;
			}
			else if (Room[j][i] == true)
			{
				/// X를 만난 경우, TempRow > 1이라면 CountCol 개수를 ++
				if (TempRow > 1)
					CountRow++;

				// X를 만났으면 개수 초기화
				TempRow = 0;
			}
		}

		if (TempRow > 1)
			CountRow++;

		// 세로
		for (int j = 0; j < n; j++)
		{
			if (Room[i][j] != true) 
			{
				TempCol++;
			}
			else if (Room[i][j] == true)
			{
				if (TempCol > 1)
					CountCol++;

				TempCol = 0;
			}
		}

		if (TempCol > 1)
			CountCol++;
	}

	cout << CountCol << ' ' << CountRow;
}

