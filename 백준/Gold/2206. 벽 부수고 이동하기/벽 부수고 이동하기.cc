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

const int MAX = 987654321;
int n, m, x, y, broke;
int ans = MAX;
int N[1002][1002];
int dist[1002][1002][2];
queue<tuple<int, int, int>> q;
string s;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> s;

		for (int j = 0; j < m; j++)
		{
			N[i][j] = s[j] - '0';
		}
	}

	// 한 칸 일 경우
	if (n == 1 && m == 1)
	{
		cout << 1;
		return 0;
	}

	dist[0][0][0] = 1;
	dist[0][0][1] = 1;

	q.push({ 0, 0, 0});

	while (!q.empty())
	{
		tie(x, y, broke) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (nx == n - 1 && ny == m - 1)
			{
				cout << dist[x][y][broke] + 1;
				return 0;
			}

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || dist[nx][ny][broke] > 0)
				continue;

			// 벽을 만났고, 이 경로에서 벽을 부순적이 없다면
			if (N[nx][ny] == 1 && broke == 0)
			{
				dist[nx][ny][1] = dist[x][y][broke] + 1;
				q.push({ nx, ny, 1 });
			}
			else if (N[nx][ny] == 0)
			{
				dist[nx][ny][broke] = dist[x][y][broke] + 1;
				q.push({ nx, ny, broke });
			}
		}
	}

	cout << -1;
}