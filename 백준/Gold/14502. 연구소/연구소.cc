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
int ans = -1;
int N[9][9];
int visited[9][9];
vector<pair<int, int>> zeros;
vector<pair<int, int>> virus;

void dfs(int y, int x)
{
	if (visited[y][x])
		return;

	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || N[ny][nx] == 1)
			continue;

		dfs(ny, nx);
	}
}

void goVirus()
{
	memset(visited, 0, sizeof(visited));

	for (pair<int, int> p : virus)
	{
		dfs(p.first, p.second);
	}
}

int go()
{
	int Ret = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j] && N[i][j] == 0)
			{
				Ret++;
			}
		}
	}

	return Ret;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> N[i][j];

			if (N[i][j] == 0)
				zeros.push_back({ i, j });
			if (N[i][j] == 2)
				virus.push_back({ i, j });
		}
	}

	for (int i = 0; i < zeros.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < j; k++)
			{
				// 벽 세우기
				N[zeros[i].first][zeros[i].second] = 1;
				N[zeros[j].first][zeros[j].second] = 1;
				N[zeros[k].first][zeros[k].second] = 1;

				// 바이러스 퍼트리기
				goVirus();

				// 영역 넓이 계산
				ans = max(ans, go());

				// 벽 원복
				N[zeros[i].first][zeros[i].second] = 0;
				N[zeros[j].first][zeros[j].second] = 0;
				N[zeros[k].first][zeros[k].second] = 0;
			}
		}
	}

	cout << ans << "\n";
}


