#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int n, m, ans, cnt;
int x, y;
int N[1004][1004];
int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> q;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> N[i][j];

			if (N[i][j] == 1 || N[i][j] == -1)
			{
				cnt++;
			}
			if (N[i][j] == 1)
			{
				q.push({ i, j });
			}
		}
	}

	if (cnt == n * m)
	{
		cout << 0;
		return 0;
	}
	else
	{
		while (!q.empty())
		{
			tie(x, y) = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + x;
				int ny = dy[i] + y;

				if (nx < 0 || nx >= m || ny < 0 || ny >= n )
					continue;

				if (N[nx][ny] == 0)
				{
					q.push({ nx, ny });

					N[nx][ny] = N[x][y] + 1;

					ans = max(ans, N[nx][ny]);
				}
			}
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (N[i][j] == 0)
				{
					ans = 0;
					break;
				}
			}
		}

		cout << ans - 1;
	}
}