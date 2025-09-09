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

#define y1 aaa

int n, m, x1, x2, y1, y2, cnt, y, x;
string s;
char room[304][304];
int visited[304][304];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	cin >> y1 >> x1 >> y2 >> x2;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			room[i][j] = s[j];
		}
	}

	x1--, y1--;
	x2--, y2--;

	queue<pair<int, int>> q;
	q.push({ y1, x1 });
	visited[y1][x1] = 1;

	while (room[y2][x2] != '0')
	{
		cnt++;
		queue<pair<int, int>> tmp;

		while (q.size())
		{
			tie(y, x) = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = dy[i] + y;
				int nx = dx[i] + x;

				if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])
					continue;

				visited[ny][nx] = cnt;

				if (room[ny][nx] != '0')
				{
					room[ny][nx] = '0';
					tmp.push({ ny, nx });
				}
				else
				{
					q.push({ ny, nx });
				}
			}
		}
		q = tmp;
	}

	cout << cnt;

	return 0;
}