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

int l, r, c, x;
char board[32][32][32];
int dist[32][32][32];
string s; 

int bfs(int z, int x, int y)
{
	queue<tuple<int, int, int>> q;
	q.push({ z, x, y });	// x y z
	dist[z][x][y] = 0;

	while (!q.empty())
	{
		tie(z, x, y) = q.front();
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nz = dz[i] + z;
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l)
				continue;

			if (dist[nz][nx][ny] >= 0 || board[nz][nx][ny] == '#')
				continue;

			// 탈출 지점
			if (board[nz][nx][ny] == 'E')
			{
				return dist[z][x][y] + 1;
			}

			q.push({ nz, nx, ny });
			dist[nz][nx][ny] = dist[z][x][y] + 1;
		}
	}

	return 0;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		cin >> l >> r >> c;

		if (l == 0 && r == 0 && c == 0)
			break;

		fill(&dist[0][0][0], &dist[0][0][0] + 32 * 32 * 32, -1);

		tuple<int, int, int> StartPos = {};

		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				cin >> s;

				for (int k = 0; k < c; k++)
				{
					board[i][j][k] = s[k];	// z x y

					if (s[k] == 'S')
					{
						StartPos = { i, j, k };
					}
				}
			}
		}

		int z = get<0>(StartPos);
		int x = get<1>(StartPos);
		int y = get<2>(StartPos);

		x = bfs(z, x, y);
		
		x != 0 ? cout << "Escaped in " << x << " minute(s)." << '\n' : cout << "Trapped!" << '\n';
	}
}