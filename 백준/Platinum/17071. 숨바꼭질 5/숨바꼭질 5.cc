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

const int MAX = 500000;
int n, k;
int turn = 1;
int visited[2][MAX + 2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;

	if (n == k)
	{
		cout << 0;
		return 0;
	}

	queue<int> q;
	q.push(n);
	visited[0][n] = 1;

	bool bFind = false;
	while (q.size())
	{
		k += turn;

		if (k > MAX || k < 0)
		{
			cout << -1;
			return 0;
		}

		if (visited[turn % 2][k])
		{
			bFind = true;
			break;
		}

		int qSize = q.size();

		for (int i = 0; i < qSize; i++)
		{
			int x = q.front();
			q.pop();

			for (int nx : {x - 1, x + 1, x * 2})
			{
				if (nx < 0 || nx > MAX || visited[turn % 2][nx])
					continue;

				if (nx == k)
				{
					bFind = true;
					break;
				}

				visited[turn % 2][nx] = visited[(turn - 1) % 2][x] + 1;
				q.push(nx);
			}

			if (bFind)
				break;
		}

		if (bFind)
			break;

		turn++;
	}

	cout << turn;

	return 0;
}