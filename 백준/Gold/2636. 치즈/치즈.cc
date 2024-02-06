#include <iostream>
#include <vector>

using namespace std;

int n, m;
int AnsTime, AnsCnt, Cnt;
int N[101][101];
bool visited[101][101];

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

vector<pair<int, int>> sideList;
vector<pair<int, int>> popList;

void dfs(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])
			continue;

		// 치즈를 만났다
		if (N[ny][nx] == 1)
		{
			bool Flag = false;
			for (int j = 0; j < popList.size(); j++)
			{
				if (popList[j].first == ny && popList[j].second == nx)
				{
					Flag = true;
					break;
				}
			}

			if (!Flag)
			{
				popList.push_back({ ny, nx });
			}
		}
		else
		{
			dfs(ny, nx);
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

			if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
			{
				sideList.push_back({ i, j });
			}
			else if (N[i][j] == 1)
			{
				// 치즈가 있는 칸 개수
				Cnt++;
			}
		}
	}

	// 치즈가 있는 동안
	AnsCnt = Cnt;

	while (Cnt)
	{
		for (int i = 0; i < sideList.size(); i++)
		{
			if (!visited[sideList[i].first][sideList[i].second])
			{
				dfs(sideList[i].first, sideList[i].second);
				fill(&visited[0][0], &visited[0][0] + 101 * 101, false);
			}
		}

		for (int i = 0; i < popList.size(); i++)
		{
			N[popList[i].first][popList[i].second] = 0;
			Cnt--;
		}

		popList.clear();

		if (Cnt)
			AnsCnt = Cnt;

		AnsTime++;
	}

	cout << AnsTime << "\n";
	cout << AnsCnt << "\n";
}