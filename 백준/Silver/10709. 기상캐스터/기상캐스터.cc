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

string s;
int h, w;
int arr[102][102];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fill(&arr[0][0], &arr[0][0] + 102 * 102, -1);

	cin >> h >> w;

	for (int i = 0; i < h; i++)
	{
		cin >> s;
		int idx = -1;

		for (int j = 0; j < w; j ++)
		{
			if (s[j] == 'c')
			{
				idx = j;
				arr[i][j] = 0;
			}
			else if (s[j] == '.' && idx != -1)
			{
				arr[i][j] = j - idx;
			}
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << arr[i][j] << ' ';
		}

		cout << "\n";
	}

	return 0;
}