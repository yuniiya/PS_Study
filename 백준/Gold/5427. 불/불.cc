#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

using namespace std;

int dx[] = { -1, 0, 1, 0};
int dy[] = { 0, 1, 0, -1 };

int player_dist[1002][1002];
int fire_dist[1002][1002];
int n, w, h;
int x, y;
char c;
int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	while (n--)
	{
		cin >> w >> h;

		for (int i = 0; i < h; i++)
		{
			fill(player_dist[i], player_dist[i] + w, 0);
			fill(fire_dist[i], fire_dist[i] + w, 0);
		}

		queue<pair<int, int>> pq;
		queue<pair<int, int>> fq;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> c;

				if (c == '.')
				{
					player_dist[i][j] = -1;
					fire_dist[i][j] = -1;
				}
				else if (c == '@')
				{
					fire_dist[i][j] = -1;
					pq.push({ i, j });
				}
				else if (c == '*')
				{
					fq.push({ i, j });
					fire_dist[i][j] = 0;
				}
			}
		}

		while (!fq.empty())
		{
			tie(x, y) = fq.front();
			fq.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + x;
				int ny = dy[i] + y;

				if (nx < 0 || nx >= h || ny < 0 || nx >= w)
					continue;

				if (fire_dist[nx][ny] > fire_dist[x][y] + 1
					|| fire_dist[nx][ny] == -1)
				{
					fire_dist[nx][ny] = fire_dist[x][y] + 1;
					fq.push({ nx, ny });
				}
			}
		}

		bool bFind = false;

		while (!pq.empty())
		{
			tie(x, y) = pq.front();
			pq.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + x;
				int ny = dy[i] + y;

				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
				{
					cout << player_dist[x][y] + 1 << "\n";
					bFind = true;
					break;
				}

				if (player_dist[nx][ny] >= 0 )
					continue;

				if (player_dist[x][y] + 1 < fire_dist[nx][ny] || fire_dist[nx][ny] == -1)
				{
					player_dist[nx][ny] = player_dist[x][y] + 1;
					pq.push({ nx, ny });
				}
			}

			if (bFind)
				break;
		}

		if (!bFind)
		{
			cout << "IMPOSSIBLE" << "\n";
		}
	}
}