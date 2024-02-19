#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <memory.h>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0,-1 };

int n, m, ans, y, x;
char N[51][51];
int visited[51][51];

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({ y, x });

	visited[y][x] = 1;

	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || N[ny][nx] == 'W')
				continue;

			visited[ny][nx] = visited[y][x] + 1;

			if (N[ny][nx] == 'L')
			{
				ans = max(ans, visited[ny][nx]);
			}

			q.push({ ny, nx });
		}
	}
}

int main()
{
	// 육지: L 바다: W
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> N[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (N[i][j] == 'L')
			{
				bfs(i, j);
				memset(visited, 0, sizeof(visited));
			}
		}
	}

	cout << ans - 1 << "\n";
}
