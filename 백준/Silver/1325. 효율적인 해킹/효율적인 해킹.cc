#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;

int n, m, a, b, MaxLen;
vector<int> adj[10001];
int LenArr[10001];
int visited[10001];

int bfs(int n)
{
	int Ret = 1;

	queue<int> Q;
	Q.push(n);

	while (!Q.empty())
	{
		int here = Q.front();
		visited[here] = true;
		Q.pop();

		for (int there : adj[here])
		{
			if (!visited[there])
			{
				visited[there] = true;

				Q.push(there);
				Ret++;
			}
		}
	}

	return Ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		LenArr[i] = bfs(i);
		MaxLen = max(MaxLen, LenArr[i]);

		memset(visited, 0, sizeof(visited));
	}
	
	for (int i = 1; i <= n ; i++)
	{
		if (LenArr[i] == MaxLen)
			cout << i << " ";
	}
}