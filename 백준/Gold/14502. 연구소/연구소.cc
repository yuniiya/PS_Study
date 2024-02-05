#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int N[9][9];
bool Visited[9][9];
int Ans;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

vector<pair<int, int>> ZeroList;
vector<pair<int, int>> VirusList;

void dfs(int y, int x)
{
	Visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if (ny < 0 || ny >= n || nx < 0 || nx >= m || Visited[ny][nx] || N[ny][nx] == 1)
			continue;

		dfs(ny, nx);
	}
}

int solve()
{
	// 조합의 경우의 수마다 Visited 초기화
	fill(&Visited[0][0], &Visited[0][0] + 9 * 9, false);

	// 바이러스 퍼트리기 -> 바이러스가 있는 위치는 Visited로 체크
	for (int i = 0; i < VirusList.size(); i++)
	{
		dfs(VirusList[i].first, VirusList[i].second);
	}
	
	// 0의 개수 세기
	int Ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 0이었으면서 바이러스가 새롭게 퍼지지 않은 위치라면 
			if (N[i][j] == 0 && !Visited[i][j])
				Ret++;
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
				ZeroList.push_back({ i, j });
			else if (N[i][j] == 2)
				VirusList.push_back({ i, j });
		}
	}

	for (int i = 0; i < ZeroList.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < j; k++)
			{
				// 벽 세우기
				N[ZeroList[i].first][ZeroList[i].second] = 1;
				N[ZeroList[j].first][ZeroList[j].second] = 1;
				N[ZeroList[k].first][ZeroList[k].second] = 1;

				Ans = max(Ans, solve());

				// 원복
				N[ZeroList[i].first][ZeroList[i].second] = 0;
				N[ZeroList[j].first][ZeroList[j].second] = 0;
				N[ZeroList[k].first][ZeroList[k].second] = 0;
			}
		}
	}

	cout << Ans << "\n";
}