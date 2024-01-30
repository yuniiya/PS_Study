#include <iostream>

using namespace std;
string s;

void Print(bool Flag, string s)
{
	s = "<" + s + ">";

	if (!Flag)
	{
		cout << s << " is not acceptable." << '\n';
	}
	else
	{
		cout << s << " is acceptable." << '\n';
	}
}

bool IsVowel(int Idx)
{
	return (Idx == 'a' || Idx == 'e' || Idx == 'i' || Idx == 'o' || Idx == 'u');
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> s)
	{
		if (s == "end")
			break;

		bool Flag = true;
		bool IsInclude = false;
		int prev = -1;
		int aCnt = 0;
		int bCnt = 0;

		for (int i = 0; i < s.size(); i++)
		{
			if (IsVowel(s[i]))
			{
				IsInclude = true;

				bCnt = 0;
				aCnt++;
			}
			else
			{
				aCnt = 0;
				bCnt++;
			}

			if (aCnt == 3 || bCnt == 3)
			{
				Flag = false;
				break;
			}

			if (prev >= 1 && prev == s[i] && (s[i] != 'e' && s[i] != 'o'))
			{
				Flag = false;
				break;
			}

			prev = s[i];
		}

		if (!IsInclude)
			Flag = false;

		Print(Flag, s);
	}
}