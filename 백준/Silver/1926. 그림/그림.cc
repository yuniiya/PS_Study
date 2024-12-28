#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
bool visited[504][504];
int N[504][504];
int n, m, cnt, width;

int bfs(int y, int x)
{
	int res = 1;

	queue<pair<int, int>> Q;

	Q.push({ y, x });
	visited[y][x] = true;

	while (!Q.empty())
	{
		tie(y, x) = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || N[ny][nx] == 0)
				continue;

			Q.push({ ny, nx });
			visited[ny][nx] = true;

			res++;
		}
	}

	return res;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

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
			if (N[i][j] == 1 && false == visited[i][j])
			{
				width = max(width, bfs(i, j));
				cnt++;
			}
		}
	}

	cout << cnt << '\n' << width;
	
}