#include <iostream>
#include <vector>

using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int n, m;
int t, k;
int Ans;

int N[54][54];
bool Visited[54][54];

void dfs(int y, int x)
{
	Visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m || Visited[ny][nx] || N[ny][nx] == 0)
			continue;

		dfs(ny, nx);
	}
}

int main()
{
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n >> m >> k;
		vector<pair<int, int>> V;

		for (int j = 0; j < k; j++)
		{
			int a, b;
			cin >> a >> b;

			N[a][b] = 1;
			V.push_back({ a, b });
		}

		for (auto iter : V)
		{
			if (Visited[iter.first][iter.second])
				continue;

			dfs(iter.first, iter.second);
			Ans++;
		}

		cout << Ans << '\n';

		Ans = 0;
		fill(&N[0][0], &N[0][0] + 54 * 54, 0);
		fill(&Visited[0][0], &Visited[0][0] + 54 * 54, false);
	}
}