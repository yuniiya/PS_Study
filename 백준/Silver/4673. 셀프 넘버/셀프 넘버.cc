#include <iostream>
#include <string>

using namespace std;
const int MAX = 10001;
int main()
{
	bool SelfNumber[MAX]{false};
	int Num = 0;

	for (int i = 1; i < MAX; i++)
	{
		string s = to_string(i);
		Num = 0;

		// 한자리 수 
		if (i < 10)
		{
			Num = i;
		}
		else
		{
			// 두 자리 이상
			for (int i = 0; i < s.size(); i++)
			{
				// 각 자리를 더한다
				Num += s[i] - '0';
			}
		}
		// 자기자신을 더한다
		Num += i;

		if (Num > MAX - 1)
			continue;

		// 셀프넘버 체크
		SelfNumber[Num] = true;
	}
	
	for (int i = 1; i < MAX; i++)
	{
		if (false == SelfNumber[i])
			cout << i << '\n';
	}
}

