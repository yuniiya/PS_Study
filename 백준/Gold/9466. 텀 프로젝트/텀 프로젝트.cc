#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

using namespace std;

int t, n, a;
int check[100002];
int arr[100002];
const int CYCLE_IN = -1;

void IsCycle(int start)
{
	int cur = start;

	while (true)
	{
		check[cur] = start;
		cur = arr[cur];

		// 자기 자신이 아닌 수를 또 방문했을 경우 -> 사이클 발생
		if (check[cur] == start)
		{
			while (check[cur] != CYCLE_IN)
			{
				check[cur] = CYCLE_IN;
				cur = arr[cur];
			}

			break;
		}
		else if (check[cur] != 0)
		{
			break;
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		int ans = 0;

		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		for (int i = 1; i <= n; i++)
		{
			if (check[i] == 0)
			{
				IsCycle(i);
			}
		}

		for (int i = 1; i <= n; i++)
		{
			if (check[i] != CYCLE_IN)
				ans++;
		}

        cout << ans << '\n';
        
		fill(check + 1, check + n + 1, 0);
	}
}