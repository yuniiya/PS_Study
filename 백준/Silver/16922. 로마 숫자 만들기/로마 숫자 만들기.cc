#include <iostream>

using namespace std;

int Numbers[4] = { 1, 5, 10, 50 };
bool Select[1001]{};
int Answer = 0;

void Dfs(int n, int Start, int Sum, int Count)
{
	if (n == Count)
	{
		if (Select[Sum])
			return;

		Select[Sum] = true;
		Answer++;

		return;
	}

	for (int i = Start; i < 4; i++)
	{
		Dfs(n, i, Sum + Numbers[i], Count + 1);
	} 
}

int main()
{
	int n;
	cin >> n;

	Dfs(n, 0, 0, 0);

	cout << Answer;
}