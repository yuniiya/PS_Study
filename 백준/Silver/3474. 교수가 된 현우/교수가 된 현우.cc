#include <iostream>
#include <algorithm>

using namespace std;

int t, n;
int main()
{	
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		
		int tCnt = 0;
		int fCnt = 0;

		for (int j = 2; j <= n; j*=2)
		{
			tCnt += n / j;
		}

		for (int j = 5; j <= n; j*=5)
		{
			fCnt += n / j;
		}

		cout << min(tCnt, fCnt) << "\n";
	}
}