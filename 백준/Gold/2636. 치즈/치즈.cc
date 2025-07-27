#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <stack>
#include <memory.h>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0,-1 };

int n, m;
int N[101][101];
int visited[101][101];
int ansTime, ansCnt;
vector<pair<int, int>> deleteLists;
void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({ y, x });

	visited[y][x] = 1;

	while (q.size())
	{
		pair<int, int> f = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + f.first;
			int nx = dx[i] + f.second;

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])
				continue;

			visited[ny][nx] = 1;

			if (N[ny][nx] == 1)
			{
				deleteLists.push_back({ ny, nx });
			}
			else
			{
				q.push({ ny, nx });
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> N[i][j];
		}
	}

	while (true)
	{
		bfs(0, 0);

		// 치즈 녹이기
		for (pair<int, int> d : deleteLists)
		{
			N[d.first][d.second] = 0;
		}

		ansCnt = deleteLists.size();
		ansTime++;
		
		bool Flag = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (N[i][j] == 1)
					Flag = true;
			}
		}

		if (!Flag)
			break;

		memset(visited, 0, sizeof(visited));
		deleteLists.clear();
	}

	cout << ansTime << "\n" << ansCnt << "\n";
}


