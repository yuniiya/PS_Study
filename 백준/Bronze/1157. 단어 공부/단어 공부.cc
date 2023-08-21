#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
	string n;
	cin >> n;

	map<char, int> Map;
	map<char, int>::iterator Iter = Map.begin();

	// 맵 초기화
	for (int i = 0; i < n.size(); i++)
	{
		// 첫번째 글자를 찾는 iter
		Iter = Map.find(n[i]);

		// 못 찾았다면, 소문자/대문자 체크
		if (Iter == Map.end())
		{
			// 소문자
			if (n[i] >= 'a' && n[i] <= 'z')
			{
				// 대문자 키도 없는지 체크
				Iter = Map.find(toupper(n[i]));
			}
			else
			{
				Iter = Map.find(tolower(n[i]));
			}

			if (Iter == Map.end())
			{
				// 키를 새롭게 넣어준다
				Map.insert(make_pair(toupper(n[i]), 1));
			}
			else
			{
				Map[toupper(n[i])]++;
			}
		}
		else
		{
			Map[toupper(n[i])]++;
		}
	}

	int Max = -1;
	int Temp = 0;
	char Answer = '\0';

	Iter = Map.begin();

	for (Iter; Iter != Map.end(); Iter++)
	{
		Temp = Iter->second;

		if (Max == Temp)
		{
			Answer = '\0';
		}
		else if(Temp > Max)
		{
			Max = Temp;
			Answer = Iter->first;
		}
	}

	if (Answer != '\0')
		cout << Answer;
	else
		cout << "?";
}
