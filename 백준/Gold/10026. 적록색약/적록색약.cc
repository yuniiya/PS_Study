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

int n;
char board[104][104];
bool visited[104][104];
stack<pair<int, int>> st;

int dfs(int x, int y, char c)
{
	st.push({ x, y });
	visited[x][y] = true;
	
	while (!st.empty())
	{
		tie(x, y) = st.top();
		st.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny])
				continue;

			if (board[nx][ny] != c)
				continue;

			st.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}

	return 1;
}

int Func()
{
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
				ans += dfs(i, j, board[i][j]);
		}
	}

	return ans;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	cout << Func() << ' ';

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'G')
				board[i][j] = 'R';
		}
	}

	cout << Func();
}