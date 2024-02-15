#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int ans = 987654321;
int N[51][51];
vector<pair<int, int>> ch;
vector<pair<int, int>> houses;

void combi(int start, vector<int> v)
{
	if (v.size() == m)
	{
		// v 전부 폐업
		for (int i = 0; i < v.size(); i++)
		{
			N[ch[v[i]].first][ch[v[i]].second] = 0;
		}

		// 각 집마다 치킨집과의 최소거리 합 구하기
		int sum = 0;
		for (int i = 0; i < houses.size(); i++)
		{
			int len = 200;
			for (int j = 0; j < ch.size(); j++)
			{
				if (N[ch[j].first][ch[j].second] == 0)
					continue;

				int x = abs(ch[j].first - houses[i].first) + abs(ch[j].second - houses[i].second);
				len = min(len, x);
			}

			sum += len;
		}

		ans = min(ans, sum);

		// 복원
		for (int i = 0; i < v.size(); i++)
		{
			N[ch[v[i]].first][ch[v[i]].second] = 2;
		}

		return;
	}

	for (int i = start + 1; i < ch.size(); i++)
	{
		v.push_back(i);
		combi(i, v);

		v.pop_back();
	}

	return;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> N[i][j];
		
			if (N[i][j] == 2)
				ch.push_back({ i, j });

			if (N[i][j] == 1)
				houses.push_back({ i, j });
		}
	}

	// ch에서 m개 뽑은 뒤, 0으로 만들기
	m = ch.size() - m;
	vector<int> v;
	combi(-1, v);

	cout << ans << "\n";
}	

