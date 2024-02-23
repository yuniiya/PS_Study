#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0,-1 };

int r, c, y, x, ans;
char N[1004][1004];
int fire_check[1004][1004];
int j_check[1004][1004];
const int INF = 987654321;

pair<int, int> j_pos;
queue<pair<int, int>> q;

int main()
{
	fill(&fire_check[0][0], &fire_check[0][0] + 1004 * 1004, INF);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> N[i][j];

			if (N[i][j] == 'F')
			{
				fire_check[i][j] = 1;
				q.push({ i, j });
			}

			if (N[i][j] == 'J')
				j_pos = { i, j };
		}
	}

	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || nx < 0 || ny >= r || nx >= c ||  N[ny][nx] == '#')
				continue;

			if (fire_check[ny][nx] == INF)
			{
				fire_check[ny][nx] = fire_check[y][x] + 1;
				q.push({ ny, nx });
			}
		}
	}

	q.push(j_pos);
	j_check[j_pos.first][j_pos.second] = 1;

	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();

		if (y == 0 || x == 0 || y == r - 1 || x == c - 1)
		{
			ans = j_check[y][x];
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || nx < 0 || ny >= r || nx >= c || j_check[ny][nx] || N[ny][nx] == '#')
				continue;
			
			if (j_check[y][x] + 1 < fire_check[ny][nx])
			{
				j_check[ny][nx] = j_check[y][x] + 1;
				q.push({ ny, nx });
			}
		}
	}

	if (ans == 0)
		cout << "IMPOSSIBLE" << "\n";
	else
		cout << ans << "\n";
}