#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

using namespace std;

int dx[] = { -2, -2, 1, -1, 2, 2, -1, 1 };
int dy[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

int dist[302][302];
int t, l;
int x, y, tx, ty;
int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		cin >> l;
		cin >> x >> y >> tx >> ty;

		if (x == tx && y == ty)
		{
			cout << 0 << '\n';
			continue;
		}

		queue<pair<int, int>> q;
		q.push({ x, y });

		bool bFind = false;

		while (!q.empty())
		{
			tie(x, y) = q.front();
			q.pop();

			for (size_t i = 0; i < 8; i++)
			{
				int nx = dx[i] + x;
				int ny = dy[i] + y;

				if (nx < 0 || nx >= l || ny < 0 || ny >= l)
					continue;

				if (dist[nx][ny] > 0)
					continue;

				if (nx == tx && ny == ty)
				{
					cout << dist[x][y] + 1 << '\n';
					bFind = true;
					break;
				}

				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx, ny });
			}

			if (bFind)
				break;
		}

		fill(&dist[0][0], &dist[0][0] + 302 * 302, 0);
	}
}