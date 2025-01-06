#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

using namespace std;

int dx[] = { -1, 0, 1, 0, 0, 0 };
int dy[] = { 0, 1, 0, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

int m, n, h, ans, x, y, z, cnt;
int board[104][104][104];
int dist[104][104][104];
int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	queue<tuple<int, int, int>> q;

	cin >> m >> n >> h;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> board[i][j][k];

				if (board[i][j][k] == 1)
				{
					q.push({ i, j, k });
				}
				if (board[i][j][k] == 1 || board[i][j][k] == -1)
				{
					cnt++;
				}
				if (board[i][j][k] == 0)
				{
					dist[i][j][k] = -1;
				}
			}
		}
	}

	if (cnt == n * m * h)
	{
		cout << 0;
		return 0;
	}

	while (!q.empty())
	{
		tie(z, x, y) = q.front();
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			int nz = dz[i] + z;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
				continue;

			if (dist[nz][nx][ny] >= 0)
				continue;

			q.push({ nz, nx, ny });
			dist[nz][nx][ny] = dist[z][x][y] + 1;

			ans = max(ans, dist[nz][nx][ny]);
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (dist[i][j][k] == -1)
				{
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << ans;
}