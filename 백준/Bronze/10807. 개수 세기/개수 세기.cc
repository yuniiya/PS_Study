#include <iostream>
#include <algorithm>

using namespace std;

int n, a;
int pos[101];
int neg[101];
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;

		if (a >= 0)
		{
			pos[a]++;
		}
		else
		{
			a = abs(a);
		
			neg[a]++;
		}
	}

	cin >> a;

	if (a >= 0)
	{
		cout << pos[a];
	}
	else
	{
		cout << neg[abs(a)];
	}
}