#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int n;
string s, Ans;
char N[65][65];

string Quard(int y, int x, int Size)
{
	if (Size == 1)
		return string(1, N[y][x]);
	
	char Target = N[y][x];
	string Ret = "";

	for (int i = y; i < y + Size; i++)
	{
		for (int j = x; j < x + Size; j++)
		{
			if (Target != N[i][j])
			{
				Ret += "(";
				
				Ret += Quard(y, x, Size / 2);
				Ret += Quard(y, x + Size / 2, Size / 2);
				Ret += Quard(y + Size / 2, x, Size / 2);
				Ret += Quard(y + Size / 2, x + Size / 2, Size / 2);

				Ret += ")";
				return Ret;
			}
		}
	}

	return string(1, Target);
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s;

		for (int j = 0; j < n; j++)
		{
			N[i][j] = s[j];
		}
	}

	cout << Quard(0, 0, n);
}