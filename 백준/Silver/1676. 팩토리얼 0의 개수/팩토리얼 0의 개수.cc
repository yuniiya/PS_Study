#include <iostream>

using namespace std;

int n, Ans;
int main()
{
	cin >> n;

	for (int i = 5; i <= n; i*=5)
	{
		Ans += n / i;
	}

	cout << Ans << "\n";
}