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

const int MAX = 1500;
int r, c, y, x, day;
string s;
char N[MAX + 2][MAX + 2];
queue<pair<int, int>> swan;
queue<pair<int, int>> tmp_swan;
queue<pair<int, int>> water;
queue<pair<int, int>> tmp_water;
int visited_water[MAX + 2][MAX + 2];
int visited_swan[MAX + 2][MAX + 2];
int swanY, swanX;

bool move()
{
	while (swan.size())
	{
		tie(y, x) = swan.front();
		swan.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited_swan[ny][nx])
				continue;

			visited_swan[ny][nx] = true;

			if (N[ny][nx] == 'L')
			{
				return true;
			}
			else if (N[ny][nx] == '.')
			{
				swan.push({ ny, nx });
			}
			else if (N[ny][nx] == 'X')
			{
				tmp_swan.push({ ny, nx });
			}
		}
	}

	return false;
}

void melt()
{
	while (water.size())
	{
		tie(y, x) = water.front();
		water.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited_water[ny][nx])
				continue;

			visited_water[ny][nx] = true;

			if (N[ny][nx] == 'X')
			{
				N[ny][nx] = '.';
				tmp_water.push({ ny, nx });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			N[i][j] = s[j];
			if (s[j] == 'L')
			{
				swanY = i;
				swanX = j;
				visited_water[i][j] = true;
				water.push({ i, j });
			}
			else if (s[j] == '.')
			{
				visited_water[i][j] = true;
				water.push({ i, j });
			}
		}
	}

	swan.push({ swanY, swanX });
	visited_swan[swanY][swanX] = true;

	while (true)
	{
		if (move())
			break;

		melt();

		swan = tmp_swan;
		water = tmp_water;

		queue<pair<int, int>> tmp;
		swap(tmp_swan, tmp);
		swap(tmp_water, tmp);

		day++;
	}

	cout << day;

	return 0;
}