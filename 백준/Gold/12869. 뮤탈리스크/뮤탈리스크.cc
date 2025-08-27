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

int n;
int N[3], visited[64][64][64];
int ans = 987654321;
vector<vector<int>> all(0, vector<int>(0, 0));

struct A
{
	int a, b, c;
};

void bfs(int x, int y, int z)
{
	queue<A> q;
	q.push({ x, y, z });
	visited[x][y][z] = 1;

	while (q.size())
	{
		x = q.front().a;
		y = q.front().b;
		z = q.front().c;

		q.pop();

		if (visited[0][0][0])
		{
			ans = min(visited[0][0][0], ans);
		}

		for (int i = 0; i < all.size(); i++)
		{
			int nx = max(0, x - all[i][0]);
			int ny = max(0, y - all[i][1]);
			int nz = max(0, z - all[i][2]);

			if (visited[nx][ny][nz])
				continue;

			visited[nx][ny][nz] = visited[x][y][z] + 1;
			q.push({ nx, ny , nz });
		}
	}
}

int main() 
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> N[i];
	}

	// 모든 경우의 수
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(9);

	do
	{
		all.push_back(v);

	} while (next_permutation(v.begin(), v.end()));


	bfs(N[0], N[1], N[2]);

	cout << ans - 1 << "\n";
}