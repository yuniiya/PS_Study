#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second < b.second;
}

int main()
{
	int Results[4]{};
	vector<int> Numbers;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		Numbers.push_back(a);
	}

	sort(Numbers.begin(), Numbers.end());

	for (int i = 0; i < 4; i++)
	{
		int Result = 0;
		switch (i)
		{
		case 0:		// 산술평균
		{	
			double r = 0;
			for (int j = 0; j < n; j++)
			{
				r += Numbers[j];
			}

			r = r / n;
			Result = (int)round(r);
		}
			break;
		case 1:		// 중앙값
		{
			Result = Numbers[n / 2];
		}
			break;
		case 2:		// 최빈값
		{
			// 숫자, 등장 횟수
			vector<pair<int, int>> CountsOfNum;

			for (int j = 0; j < n; j++)
			{
				int Target = Numbers[j];
				// 등장 횟수
				int Count = 0;
				bool Flag = false;

				if (false == CountsOfNum.empty())
				{
					// 현재 타깃과 CountsOfNum에 있는 숫자가 같은지 확인
					for (int k = 0; k < CountsOfNum.size(); k++)
					{
						if (CountsOfNum[k].first == Target)
						{
							Flag = false;
							CountsOfNum[k].second++;
							continue;
						}

						Flag = true;
					}
				}
				else
				{
					CountsOfNum.push_back(make_pair(Target, ++Count));
				}

				if(Flag)
				{
					// 없다면 새롭게 넣어주기
					CountsOfNum.push_back(make_pair(Target, ++Count));
				}
			}
			
			vector<int> Modes;	// 최빈값

			int MaxIdx = (int)CountsOfNum.size() - 1;
			// 원소가 1개 이상일 때만
			if (CountsOfNum.size() > 1)
			{
				// 등장 횟수 기준으로 정렬
				sort(CountsOfNum.begin(), CountsOfNum.end(), compare);
				// 최다 등장 횟수
				int Max = CountsOfNum[MaxIdx].second;
			
				// 최다 등장 횟수와, 이전 숫자의 Count가 같다면 최빈값이 같은 수가 있다는 뜻
				if (Max == CountsOfNum[MaxIdx - 1].second)
				{
					// Modes에 넣어두기
					for (int j = 0; j < CountsOfNum.size(); j++)
					{
						if (Max == CountsOfNum[j].second)
						{
							Modes.push_back(CountsOfNum[j].first);
						}
					}

					// 정렬 후, 두번째로 작은 값 
					sort(Modes.begin(), Modes.end());
					Result = Modes[1];
				}
				else
				{
					Result = CountsOfNum[MaxIdx].first;
				}

			}
			else
			{
				Result = CountsOfNum[0].first;
			}
		}
			break;
		case 3:		// 범위
		{
			Result = Numbers[n - 1] - Numbers[0];
		}
			break;
		}

		Results[i] = Result;
	}

	// 결과 출력
	for (int i = 0; i < 4; i++)
	{
		cout << Results[i] << endl;
	}
}