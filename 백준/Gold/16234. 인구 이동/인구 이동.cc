#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0,-1 };

int n, l, r, ans, sum;
int N[51][51];
int visited[51][51];
vector<pair<int, int>> vp;

void dfs(int y, int x)
{
	if (visited[y][x])
		return;

	visited[y][x] = true;
	vp.push_back({ y, x });
	sum += N[y][x];

	for (int i = 0; i < 4; i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])
			continue;
		
		if (l <= abs(N[ny][nx] - N[y][x]) && r >= abs(N[ny][nx] - N[y][x]))
		{
			dfs(ny, nx);
		}
	}	
}

int main()
{
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> N[i][j];
		}
	}

	while (true)
	{
		bool Flag = false;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j])
				{
					vp.clear();
					sum = 0;
					dfs(i, j);

					if (vp.size() == 1)
						continue;

					// 인구 이동
					for (pair<int, int> p : vp)
					{
						N[p.first][p.second] = sum / vp.size();
						Flag = true;
					}
				}
			}
		}

		if (!Flag)
			break;

		memset(visited, 0, sizeof(visited));
		ans++;
	}

	cout << ans << "\n";
}
