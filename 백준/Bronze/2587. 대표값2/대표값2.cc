#include <iostream>
#include <algorithm>

using namespace std;

int sum;
int N[5];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
	{
		cin >> N[i];
		
		sum += N[i];
	}

	sort(N, N + 5);

	cout << sum / 5 << '\n' << N[2];
}