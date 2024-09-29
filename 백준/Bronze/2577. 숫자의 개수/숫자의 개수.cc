#include <iostream>
#include <string>

using namespace std;

int a, b, c;
int N[10];
int main(void)
{
	cin >> a >> b >> c;

	long long result = a * b * c;
	string s = to_string(result);

	for (int i = 0; i < s.size(); i++)
	{
		N[s[i] - '0']++;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << N[i] << '\n';
	}
}