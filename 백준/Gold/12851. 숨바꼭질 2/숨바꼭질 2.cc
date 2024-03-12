#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100000;
int n, k;
int visited[MAX + 4];
int cnt[MAX + 4];
int main()
{
	cin >> n >> k;

	if (n == k)
	{
		cout << 0 << "\n" << 1 << "\n";
        exit(0);
	}

	queue<int> q;
	q.push(n);

	visited[n] = 1;
	cnt[n] = 1;

	while (q.size()) 
	{
		// 현재 위치
		int now = q.front();
		q.pop();
		
		for (int next : {now - 1, now + 1, now * 2})
		{
			if (0 <= next && next <= MAX)
			{
				// 1. 방문한 적 없는 위치라면
				if (!visited[next])
				{
					q.push(next);

					// 현재 지점까지 최단거리
					visited[next] = visited[now] + 1;
					// 현재 지점까지 경우의 수 기록
					cnt[next] += cnt[now];
				}
				// 2. k에 도달했고, 최단거리라면
				else if (visited[next] == visited[now] + 1)
				{
					// 경우의 수 기록
					cnt[next] += cnt[now];
				}
			}
		}
	}

	cout << visited[k] - 1 << "\n";
	cout << cnt[k] << "\n";
}