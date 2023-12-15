#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int h;
int n;
int Ans;
int Ret;
int tx, ty;
int N[104][104];
int M[104][104];
bool Visited[104][104];
int Idx[104];
void dfs(int y, int x)
{
	Visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || nx >= n || ny >= n)
			continue;

		if (Visited[ny][nx] || M[ny][nx] == 0)
			continue;

		dfs(ny, nx);
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> N[i][j];
			h = max(h, N[i][j]);
		}
	}

	int th = h;
	h--;

	while (h >= 0)
	{
		vector<pair<int, int>> V;

		// 영역 계산
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (N[i][j] > h)
				{
					M[i][j] = 1;
					V.push_back({ i, j });
				}
			}
		}

		for (auto i : V)
		{
			tie(ty, tx) = i;

			if (!Visited[ty][tx])
			{
				dfs(ty, tx);
				Ret++;
			}
		}

		Ans = max(Ret, Ans);
		Ret = 0;

		fill(&M[0][0], &M[0][0] + 104 * 104, 0);
		fill(&Visited[0][0], &Visited[0][0] + 104 * 104, false);
		h--;
	}

	cout << Ans << endl;
}