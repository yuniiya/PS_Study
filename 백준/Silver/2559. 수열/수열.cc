#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> V;
	vector<int> Sum;
	vector<int> Ans;

	int n, k;
	cin >> n >> k;

	Sum.resize(n);

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		V.push_back(a);
		// 부분합 저장
		if (i != 0)
			Sum[i] = Sum[i - 1] + a;
		else
			Sum[i] = a;
	}
	
	int Idx = k - 1;
	int i = -1;
	while (Idx != n)
	{
		if (i != -1)
			Ans.push_back(Sum[Idx] - Sum[i]);
		else
			Ans.push_back(Sum[Idx]);
		
		i++;
		Idx++;
	}

	sort(Ans.begin(), Ans.end());
	cout << Ans.back();
}