#include <iostream>

using namespace std;

int n, x, a, ans;
int N[1000001];
bool marking[1000001];
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> N[i];
	}

	cin >> x;

	for (int i = 0; i < n; i++)
	{
		if (x - N[i] > 0 && marking[x - N[i]])
		{
			ans++;
		}

		marking[N[i]] = true;
	}
	cout << ans;
}