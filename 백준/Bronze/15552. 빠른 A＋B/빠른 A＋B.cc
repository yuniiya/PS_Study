#include <iostream>

using namespace std;

int t;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int a, b;
		cin >> a >> b;

		cout << a + b << '\n';
	}
}