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

int r, c;
int ans = 1;
string s;
char N[24][24];
int visited[24][24];
int alpha[26];

void dfs(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if (ny <= 0 || ny > r || nx <= 0 || nx > c || visited[ny][nx])
			continue;

		if (alpha[N[ny][nx] - 'A'])
			continue;

		alpha[N[ny][nx] - 'A'] = 1;
		visited[ny][nx] = visited[y][x] + 1;
		ans = max(ans, visited[ny][nx]);
		dfs(ny, nx);
		alpha[N[ny][nx] - 'A'] = 0;
		visited[ny][nx] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c;

	for (int i = 1; i <= r; i++)
	{
		cin >> s;
		for (int j = 1; j <= c; j++)
		{
			N[i][j] = s[j - 1];
		}
	}

	alpha[N[1][1] - 'A'] = 1;
	visited[1][1] = 1;

	dfs(1, 1);

	cout << ans;
	
	return 0;
}