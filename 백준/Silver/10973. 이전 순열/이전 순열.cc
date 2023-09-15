#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
	int n;
	vector<int> Numbers;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		Numbers.push_back(a);
	}

	int i = n - 2;			// 기준점을 찾을 시작지점
	int j = n - 1;			// 맨 뒤부터 시작

	while (i >= 0 && Numbers[i] < Numbers[i + 1])
	{
		i--;
	}

	if (i >= 0)
	{
		while (j >= i && Numbers[j] > Numbers[i])
		{
			j--;
		}

		swap(Numbers[i], Numbers[j]);

		sort(Numbers.begin() + (i + 1), Numbers.end(), greater<int>());

		for (int k = 0; k < n; k++)
		{
			cout << Numbers[k] << ' ';
		}
	}
	else
	{
		cout << -1 << endl;
	}
}
