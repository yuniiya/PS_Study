#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;
int Alpha[26];
string Ans;
int main()
{
	string s;
	cin >> s;

	for (char c : s)
	{
		Alpha[c - 'A']++;
	}

	// 홀수개 알파벳 개수 체크
	int OddCnt = 0;
	int OddIdx = -1;

	for (int i = 0; i < 26; i++)
	{
		if (Alpha[i] % 2 != 0)
		{
			OddCnt++;
			OddIdx = i;
		}
	}

	if (OddCnt > 1)
	{
		cout << "I'm Sorry Hansoo" << endl;
	}
	else
	{
		if (OddIdx != -1)
			Alpha[OddIdx]--;

		for (int i = 0; i < 26; i++)
		{
			if (Alpha[i])
			{
				for (int j = 0; j < Alpha[i] / 2; j++)
				{
					Ans += (char)(i + 'A');
				}
			}
		}

		string Rev = Ans;
		reverse(Rev.begin(), Rev.end());

		if (OddIdx != -1)
			Ans += (char)(OddIdx + 'A');

		Ans += Rev;

		cout << Ans << endl;
	}
}