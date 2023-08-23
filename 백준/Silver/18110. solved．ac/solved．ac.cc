#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
const float PERCENT = 0.15f;
int main()
{
	vector<int> Scores;
	int Answer = 0;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		Scores.push_back(a);
	}

	sort(Scores.begin(), Scores.end());

	int ExceptPeople = 0;
	// 제외할 사람 수 
	if (Scores.size() > 0)
	{
		ExceptPeople = round((int)Scores.size() * PERCENT);
		float Temp = 0.f;

		// 절사평균만큼 제외하고 계산할 점수
		for (int i = ExceptPeople; i < ((int)Scores.size() - ExceptPeople); i++)
		{
			Temp += Scores[i];	
		}

		Answer = round(Temp / (Scores.size() - (ExceptPeople * 2)));
	}

	// 최종 평균 난이도
	if (Answer > 0)
		cout << Answer;
	else
		cout << 0;
}

