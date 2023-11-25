#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N[9];
vector<int> Ans;
int sum;
pair<int, int> P;
void solve()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (sum - N[i] - N[j] == 100)
			{
				P = { i, j };
				return;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 9명 중에 7명 뽑았을 때, 합이 100
	for (int i = 0; i < 9; i++)
	{
		cin >> N[i];
		sum += N[i];
	}

	solve();

	// 인덱스 i, j는 빼고 출력
	for (int i = 0; i < 9; i++)
	{
		if (i == P.first || i == P.second)
			continue;

		Ans.push_back(N[i]);
	}

	sort(Ans.begin(), Ans.end());
	for (int i : Ans)
	{
		cout << i << '\n';
	}
}