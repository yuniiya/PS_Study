#include <iostream>

using namespace std;
string s;
char Array[] = {'a', 'e', 'i', 'o', 'u'};

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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> s)
	{
		if (s == "end")
			exit(0);

		bool ac = false;

		for (int i = 0; i < 5; i++)
		{
			if (s.find(Array[i]) != string::npos)
			{
				ac = true;
				break;
			}
		}

		if (!ac)
		{
			Print(ac, s);
			continue;
		}

		// 자음 연속 3개 or 모음 연속 3개
		int aCnt = 0;
		int bCnt = 0;
		for (int i = 0; i < s.size(); i++)
		{
			// 모음이라면
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			{
				if (bCnt != 0)
					bCnt = 0;

				aCnt++;
			}
			else
			{
				if (aCnt != 0)
					aCnt = 0;

				bCnt++;
			}

			if (aCnt == 3 || bCnt == 3)
			{
				ac = false;
				break;
			}
		}

		if (!ac)
		{
			Print(ac, s);
			continue;
		}

		// 같은 글자 연속 두번 (ee와 oo는 허용)
		int j = 0;
		for (int i = 0; i < s.size() - 1; i++)
		{
			j = i + 1;

			if (s[i] == s[j] && (s[i] != 'e' && s[i] != 'o'))
			{
				ac = false;
				break;
			}
		}

		if (!ac)
		{
			Print(ac, s);
			continue;
		}

		Print(ac, s);
	}
}