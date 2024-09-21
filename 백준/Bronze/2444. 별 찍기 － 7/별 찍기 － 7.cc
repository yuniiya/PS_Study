#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a;
	cin >> a;

	int star = -1;

	for (int i = 1; i < a * 2; i++)
	{
		if (i <= a)
			star += 2;
		else
			star -= 2;

		int blank = (a * 2 - star) / 2;

		for (int k = 0; k < blank; k++)
		{
			cout << ' ';
		}
		for (int k = 0; k < star; k++)
		{
			cout << '*';
		}
		
		cout << "\n";
	}
}	