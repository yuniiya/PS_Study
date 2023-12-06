#include <iostream>

using namespace std;
typedef long long ll;
ll a, b, c;
ll go(ll a, ll b)
{
	if (b == 1)
		return a % c;

	ll Ret = go(a, b / 2);
	Ret = (Ret * Ret) % c;

	if (b % 2)
		Ret = (Ret * a) % c;

	return Ret;
}

int main()
{
	cin >> a >> b >> c;

	cout << go(a, b);
}
