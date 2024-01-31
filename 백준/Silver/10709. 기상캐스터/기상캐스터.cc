#include <iostream>
#include <string>

using namespace std;

int h, w;
string s;
string S[101];
int Ans[101][101];
int main()
{
	cin >> h >> w;

	for (int i = 0; i < h; i++)
	{
		cin >> s;

		S[i] = s;
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			// 처음부터 구름이 있던 자리
			if (S[i][j] == 'c')
				continue;

			// 왼쪽 잘라오기
			string tmp = S[i].substr(0, j);		
				
			// 왼쪽에 구름이 있는지 체크
			if (tmp.find('c') == string::npos)
			{
				Ans[i][j] = -1;
				continue;
			}
		
			// 구룸이 여러개라면, 가장 가까운 인덱스
			int ccnt = 0;
			int Idx = -1;
			for (int k = 0; k < tmp.size(); k++)
			{
				if (tmp[k] == 'c')
				{
					ccnt++;
					Idx = k;
				}
			}

			if (ccnt > 1)
			{
				Ans[i][j] = j - Idx;
			}
			else
			{
				Ans[i][j] = (j - (int)tmp.find('c'));
			}
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << Ans[i][j] << ' ';
		}
		
		cout << '\n';
	}
}