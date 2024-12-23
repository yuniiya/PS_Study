#include <iostream>
#include <algorithm>
#include <deque>
#include <sstream>

using namespace std;

int t, n;
string s, arr;
int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		deque<int> dq;
		cin >> s >> n >> arr; 

		if (n > 0)
		{
			// [ ] 자르기
			arr = arr.substr(1, arr.size() - 1);

			// 숫자 파싱
			istringstream stream(arr);
			string tmp;

			while (getline(stream, tmp, ','))
			{
				dq.push_back(stoi(tmp));
			}
		}

		// 함수 실행

		bool IsReverse = false;
		bool bError = false;

		for (char c : s)
		{
			if (c == 'R')
			{
				IsReverse = !IsReverse;
			}
			else if (c == 'D')
			{
				if (dq.empty())
				{
					bError = true;
					cout << "error" << '\n';
					break;
				}

				if (IsReverse)
				{
					dq.pop_back();
				}
				else
				{
					dq.pop_front();
				}
			}
		}

		if (!bError)
		{
			cout << '[';

			if (IsReverse)
			{
				for (int j = (int)dq.size() - 1; j >= 0; j--)
				{
					cout << dq[j];

					if (j != 0)
					{
						cout << ',';
					}
				}
			}
			else
			{
				for (int j = 0; j < (int)dq.size(); j++)
				{
					cout << dq[j];

					if (j != (int)dq.size() - 1)
					{
						cout << ',';
					}
				}
			}

			cout << ']' << '\n';
		}
	}
}