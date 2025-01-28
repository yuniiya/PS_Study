#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

using namespace std;

//int dx[] = { -1, 0, 1, 0 };
//int dy[] = { 0, 1, 0, -1 };

int f, s, g, u, d, ans;
int stair[1000004];
int visited[1000004];
int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> f >> s >> g >> u >> d;
	
	int dir[] = { u, -d };

	queue<int> q;
	q.push(s);
	visited[s] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < 2; i++)
		{
			int nxt = cur + dir[i];

			if (nxt <= 0 || nxt > f || visited[nxt] > 0)
				continue;

			q.push(nxt);
			visited[nxt] = visited[cur] + 1;
		}
	}

	if (visited[g] == 0)
	{
		cout << "use the stairs";

	}
	else
	{
		cout << visited[g] - 1;
	}
}