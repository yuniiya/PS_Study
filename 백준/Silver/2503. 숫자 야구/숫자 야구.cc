#include <iostream>
#include <string>

using namespace std;
int main()
{
	bool Answer[1000]{};
	// 배열의 시작부터 Dest까지 true로 채운다.
	fill_n(Answer, 1000, true);		

	for (int i = 123; i <= 987; i++)
	{
		string s = to_string(i);

		// 동일 숫자 있는 수는 제외
		if (s[0] == s[1] || s[1] == s[2] || s[0] == s[2])
		{
			Answer[i] = false;
		}
		if (s[0] == '0' || s[1] == '0' || s[2] == '0')
		{
			Answer[i] = false;
		}
	}

	int n;
	cin >> n;

	while (n--)
	{
		int Number; int Strike; int Ball;
		cin >> Number >> Strike >> Ball;

		for (int i = 123; i <= 987; i++)
		{
			// 답일 가능성이 있다면
			if (true == Answer[i])
			{
				int StrCnt = 0;
				int BallCnt = 0;

				string TempNum = to_string(Number);
				string TempI = to_string(i);

				// 자릿수 비교
				for (int j = 0; j < 3; j++)
				{
					for (int k = 0; k < 3; k++)
					{
						// 같은 숫자 
						if (TempNum[j] == TempI[k])
						{
							if (j == k)
							{
								// 같은 자릿수면, 스트라이크 ++
								StrCnt++;
							}
							else
							{
								// 다른 자릿수면, 볼 ++
								BallCnt++;
							}
						}
					}
				}

				// 입력받은 수와 같지 않다면 답에서 제외
				if (StrCnt != Strike || BallCnt != Ball)
				{
					Answer[i] = false;
				}
			}
		}
	}

	int Result = 0;
	for (int i = 123; i <= 987; i++)
	{
		if (true == Answer[i])
		{
			Result++;
		}
	}

	cout << Result;
}
