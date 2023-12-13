#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m;
vector<int> G[101];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int bfs(int _x, int _y)
{
	queue<pair<int, int>> Q;
	Q.push({_x, _y});

	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;

			if (G[nx][ny] == 0)
				continue;

			if (G[nx][ny] == 1)
			{
				Q.push({ nx, ny });
				G[nx][ny] = G[x][y] + 1;
			}
		}
	}

	return G[n - 1][m - 1];
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char a;
			cin >> a;
			G[i].push_back(a - '0');
		}
	}

	cout << bfs(0, 0) << endl;
}