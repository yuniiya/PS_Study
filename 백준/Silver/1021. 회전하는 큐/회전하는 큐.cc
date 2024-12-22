#include <iostream>
#include <deque>

using namespace std;

int n, m, a, ans, idx;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	deque<int> dq;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		dq.push_back(i);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a;
		
		if (dq.front() == a)
		{
			dq.pop_front();
		}
		else
		{
			bool bLeft = false;

			for (int j = 0; j < (int)dq.size(); j++)
			{
				if (dq[j] == a)
				{
					idx = j;
					bLeft = idx < (int)dq.size() - idx ? true : false;

					break;
				}
			}

			if (bLeft)
			{
				while (dq.front() != a)
				{
					dq.push_back(dq.front());
					dq.pop_front();

					ans++;
				}
			}
			else
			{
				while (dq.front() != a)
				{
					dq.push_front(dq.back());
					dq.pop_back();

					ans++;
				}
			}

			// a가 front까지 와서 while문이 끝났을 때의 처리 필요
			dq.pop_front();
		}
	}

	cout << ans;
}