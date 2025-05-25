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

int n, m, k;
int lx, ly, rx, ry;
int dist[102][102];
vector<int> arr;

int bfs(int y, int x) 
{
	int ret = 1;

	queue<pair<int, int>> q;
	q.push({ y, x });
	dist[y][x] = 1;

	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || ny >= m || nx < 0 || nx >= n || dist[ny][nx] != 0)
				continue;

			dist[ny][nx] = dist[y][x] + 1;
			q.push({ ny, nx });
			ret++;
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n >> k;

	while (k--)
	{
		cin >> lx >> ly >> rx >> ry;

		for (int i = m - ry; i < m - ly; i++)
		{
			for (int j = lx; j < rx; j++)
			{
				dist[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j  < n; j ++)
		{
			if (dist[i][j] == 0) 
			{
				arr.push_back(bfs(i, j));
			}
		}
	}

	sort(arr.begin(), arr.end());

	cout << arr.size() << "\n";
	for (int i : arr)
	{
		cout << i << " ";
	}

	return 0;
}
