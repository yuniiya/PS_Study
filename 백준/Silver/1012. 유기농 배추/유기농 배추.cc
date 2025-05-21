#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>
#include <map>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int t, n, m, k;
int board[52][52];
bool visited[52][52];

void dfs(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])
			continue;

		if (board[ny][nx] == 0)
			continue;

		dfs(ny, nx);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--)
	{
		int ret = 0;
		cin	>> m >> n >> k;
		
		for (int i = 0; i < k; i++)
		{
			int a, b;
			cin >> a >> b;

			board[b][a] = 1;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == 1 && !visited[i][j])
				{
					ret++;
					dfs(i, j);
				}
			}
		}

		cout << ret << "\n";

		fill(&board[0][0], &board[0][0] + 52 * 52, 0);
		fill(&visited[0][0], &visited[0][0] + 52 * 52, false);
	}

	return 0;
}
