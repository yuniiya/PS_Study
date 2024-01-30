#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int m, n, k;
int lx, ly, rx, ry;
int N[101][101];
bool Visited[101][101];
vector<int> V;

int dfs(int y, int x)
{
	int Ret = 1;

	if (Visited[y][x])
	{
		return Ret;
	}

	Visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if (ny >= m || nx >= n || ny < 0 || nx < 0 || N[ny][nx] != 0)
			continue;

		if (!Visited[ny][nx])
		{
			Ret += dfs(ny, nx);
		}
	}

	return Ret;
}

int main()
{
	cin >> m >> n >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> lx >> ly >> rx >> ry;

		for (int y = ly; y < ry; y++)
		{
			for (int x = lx; x < rx; x++)
			{
				N[y][x] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (N[i][j] == 0 && !Visited[i][j])
			{
				V.push_back({ dfs(i, j) });
			}
		}
	}

	sort(V.begin(), V.end());

	cout << V.size() << endl;

	for (auto v : V)
	{
		cout << v << " ";
	}
}