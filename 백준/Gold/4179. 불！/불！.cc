#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <tuple>
#include <deque>

using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int r, c, ans;
int x, y;
string s;
char board[1004][1004];
bool jh_visited[1004][1004];
int dist[1004][1004];
int fire_dist[1004][1004];

const int MAX = 987654321;
int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> fire;
	queue<pair<int, int>> jh;

	fill(&fire_dist[0][0], &fire_dist[0][0] + 1004 * 1004, -1);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		cin >> s;

		for (int j = 0; j < c; j++)
		{
			board[i][j] = s[j];

			if (s[j] == 'F')
			{
				fire.push({ i, j });
				fire_dist[i][j] = 0;
			}
			if (s[j] == 'J')
			{
				jh.push({ i, j });
			}
		}
	}

	// 불 이동
	while (!fire.empty())
	{
		tie(x, y) = fire.front();
		fire.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;

			if (board[nx][ny] != '#')
			{
				// 이미 불이 있을 경우에 대한 예외처리
				if (board[nx][ny] == 'F' && fire_dist[nx][ny] <= fire_dist[x][y] + 1)
					continue;

				board[nx][ny] = 'F';
				fire.push({ nx, ny });
				fire_dist[nx][ny] = fire_dist[x][y] + 1;					
			}
		}
	}

	// 지훈 이동
	while (!jh.empty())
	{
		tie(x, y) = jh.front();
		jh.pop();

		jh_visited[x][y] = true;

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			{
				cout << dist[x][y] + 1;
				return 0;
			}
				//continue;

			if (board[nx][ny] == '#' || jh_visited[nx][ny])
				continue;

			if (fire_dist[nx][ny] == -1 || dist[x][y] + 1 < fire_dist[nx][ny])
			{
				jh_visited[nx][ny] = true;
				jh.push({ nx, ny });
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}

	cout << "IMPOSSIBLE";
}