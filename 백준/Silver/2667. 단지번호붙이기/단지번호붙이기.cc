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

int n, cnt;
string s;
int board[25][25];
vector<int> v;

int bfs(int x, int y)
{
	int ret = 1;

	queue<pair<int, int>> q;
	q.push({ x, y });
	board[x][y] = cnt;

	while(!q.empty())
	{
		tie(x, y) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] >= 0)
				continue;

			q.push({ nx, ny });
			board[nx][ny] = cnt;
			ret++;
		}
	}

	return ret;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s;

		for (int j = 0; j < n; j++)
		{
			if (s[j] - '0' == 1)
			{
				board[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == -1)
			{
				cnt++;
				v.push_back(bfs(i, j));
			}
		}
	}
	cout << (int)v.size() << '\n';
	
	sort(v.begin(), v.end());
	
	for (int i : v)
	{
		cout << i << "\n";
	}
}