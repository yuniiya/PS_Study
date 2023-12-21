#include <bits/stdc++.h>

using namespace std;
#define y1 aaaa

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int n, m, k;
int Cnt;
int y1, x1, y2, x2;
int N[104][104];
bool Visited[104][104];
vector<int> V;

int dfs(int y, int x)
{
	Visited[y][x] = true;
	int Ans = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m)
			continue;

		if (N[ny][nx] == 0 && !Visited[ny][nx])
			Ans += dfs(ny, nx);
	}

	return Ans;
}

int main()
{
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = y1; j < y2; j++)
		{
			for (int l = x1; l < x2; l++)
			{
				N[j][l] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!Visited[i][j] && N[i][j] == 0)
			{
				V.push_back(dfs(i, j));
				Cnt++;
			}
		}
	}

	cout << Cnt << '\n';

	sort(V.begin(), V.end());

	for (auto v : V)
	{
		cout << v << ' ';
	}
}