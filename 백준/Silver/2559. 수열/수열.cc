#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>
#include <map>

using namespace std;

int n, k, a;
int ans = -987654321;
int psum[100002];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> a;

		psum[i] = a + psum[i - 1];
	}

	for (int i = k; i <= n; i++)
	{
		ans = max(ans, psum[i] - psum[i - k]);
	}

	cout << ans << "\n";

	return 0;
}