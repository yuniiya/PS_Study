#include <iostream>

using namespace std;

int n, m, j, k;
int Ans;
int main()
{
	cin >> n >> m >> j;

	int StartCursor = 1;
	int EndCursor = m;
	
	for (int i = 0; i < j; i++)
	{
		cin >> k;
	
		int Cnt = 0;

		if (EndCursor < k)
		{
			while (EndCursor < k)
			{
				StartCursor++;
				EndCursor++;
				Cnt++;
			}

			if (EndCursor != k)
				continue;
		}
		else if (k < StartCursor)
		{
			while (StartCursor > k)
			{
				StartCursor--;
				EndCursor--;
				Cnt++;
			}

			if (StartCursor != k)
				continue;
		}

		Ans += Cnt;
	}

	cout << Ans << endl;
}