#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int n;
string s;
char N[65][65];

string Quard(int y, int x, int Size)
{
	// 더이상 쪼갤 수 없다면
	if (Size == 1)
		return string(1, N[y][x]);

	string Ret = "";
	char Target = N[y][x];

	for (int i = y; i < y + Size; i++)
	{
		for (int j = x; j < x + Size; j++)
		{
			// 다르다면 크기를 반으로 나눠서 다시 탐색
			if (Target != N[i][j])
			{
				Ret += "(";

				Ret += Quard(y, x, Size / 2);							// 왼쪽 위
				Ret += Quard(y, x + Size / 2, Size / 2);				// 오른쪽 위
				Ret += Quard(y + Size / 2, x, Size / 2);				// 왼쪽 아래
				Ret += Quard(y + Size / 2, x + Size / 2, Size / 2);		// 오른쪽 아래

				// 네 부분 모두 탐색을 마쳤다면 닫아서 반환
				Ret += ")";
				return Ret;
			}
		}
	}

	// 다르지 않다면
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

	cout << Quard(0, 0, n) << endl;
}