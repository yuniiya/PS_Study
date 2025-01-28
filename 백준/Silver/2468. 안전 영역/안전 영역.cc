#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <memory.h>

using namespace std;

int N[101][101];
bool Visited[101][101];
int n;
int Ans = 1;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void dfs(int y, int x, int d)
{
	Visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if (ny >= n || nx >= n || ny < 0 || nx < 0)
			continue;

		if (!Visited[ny][nx] && N[ny][nx] > d)
			dfs(ny, nx, d);
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> N[i][j];
		}
	}

	for (int d = 1; d <= 100; d++)
	{
		int Ret = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!Visited[i][j] && N[i][j] > d)
				{
					dfs(i, j, d);
					Ret++;
				}
			}
		}

		Ans = max(Ans, Ret);

		fill(&Visited[0][0], &Visited[0][0] + 101 * 101, false);
	}

	cout << Ans << endl;
}