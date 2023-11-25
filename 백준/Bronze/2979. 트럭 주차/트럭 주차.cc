#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
map<int, vector<bool>> M;
int Start = 101, End;
int Ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	for (int i = 0; i < 3; i++)
	{
		int n, m;
		cin >> n >> m;

		vector<bool> B;
		B.resize(m);

		// n~m까지 true로 채워넣고, map에 보관
		for (int j = n; j < m; j++)
		{
			B[j] = true;
		}

		M.insert({i, B});

		Start = min(n, Start);
		End = max(m, End);
	}

	// map의 각 vector의 요소가 true라면, Cnt++;
	// Cnt가 1이라면 요금은 a, 2라면 b, 3이라면 c
	// Ans += Cnt * 요금

	for (int i = Start; i < End; i++)
	{
		int Cnt = 0;

		for (int j = 0; j < 3; j++)
		{
			if (i >= M[j].size())
				continue;

			if (true == M[j][i])
				Cnt++;
		}

		if (1 == Cnt)
			Ans += a;
		else if (2 == Cnt)
			Ans += b * Cnt;
		else
			Ans += c * Cnt;
	}

	cout << Ans; 
}