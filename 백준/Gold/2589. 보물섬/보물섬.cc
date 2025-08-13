#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>
#include <map>
#include <unordered_map>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

vector<pair<int, int>> t;
char N[52][52];
int visited[52][52];
int n, m;
string s;
int ans = 1;
int bfs(int y, int x)
{
	int ret = 0;
	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y, x });

	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || N[ny][nx] == 'W')
				continue;

			q.push({ ny, nx });
			ret = visited[ny][nx] = visited[y][x] + 1;
		}
	}

	return ret - 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	
	fill(&N[0][0], &N[0][0] + 52 * 52, 'W');
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			N[i][j] = s[j];

			if (s[j] == 'L')
				t.push_back({ i, j });
		}
	}

	for (pair<int, int> p : t)
	{
		int ret = bfs(p.first, p.second);
		ans = max(ret, ans);
		memset(visited, 0, sizeof(visited));
	}

	cout << ans;

	return 0;
}