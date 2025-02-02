#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int n, m, a;
int board[302][302];
bool visited[302][302];
int ans;
vector<pair<int, int>> NewSea;
void Melt(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty())
	{
		tie(x, y) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny])
				continue;

			if (board[nx][ny] == -1)
			{
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
			if (board[nx][ny] > 0)
			{
				board[nx][ny]--;
				if (board[nx][ny] == 0)
				{
					NewSea.push_back({ nx,ny });
				}
			}
		}
	}
}

bool CheckArea(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty())
	{
		tie(x, y) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny])
				continue;

			if (board[nx][ny] > 0)
			{
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}

	return true;
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
			cin >> a;

			a == 0 ? board[i][j] = -1 : board[i][j] = a;	// 바다는 1로 체크
		}
	}

	while (true)
	{
		int area = 0;

		fill(&visited[0][0], &visited[0][0] + 302 * 302, 0);

		// 빙산 개수 체크
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] > 0 && !visited[i][j])
				{
					area += CheckArea(i, j);
				}
			}
		}

		if (area >= 2)
		{
			cout << ans;
			return 0;
		}
		if (area == 0)
		{
			cout << 0;
			return 0;
		}

		fill(&visited[0][0], &visited[0][0] + 302 * 302, 0);

		// 빙산 녹이기
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == -1 && !visited[i][j])
				{
					Melt(i, j);
				}
			}
		}

		// 새롭게 바다가 된 곳 체크
		for (auto s : NewSea)
		{
			board[s.first][s.second] = -1;
		}

		ans++;
	}
}