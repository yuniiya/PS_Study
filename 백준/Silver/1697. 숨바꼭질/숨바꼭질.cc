#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int board[200002];
int n, k;
queue<int> q;

void Func(int x, int dist)
{
	if (x < 0 || x > 100000)
		return;

	if (board[x] > 0 && x != k)
		return;

	if (x == k)
	{
		cout << dist;
		exit(0);
	}

	board[x] = dist;
	q.push(x);
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	if (n == k)
	{
		cout << 0;
		return 0;
	}

	q.push(n);

	while (!q.empty())
	{
		int t = q.front();
		q.pop();

		Func(t + 1, board[t] + 1);
		Func(t - 1, board[t] + 1);
		Func(t * 2, board[t] + 1);
	}
}