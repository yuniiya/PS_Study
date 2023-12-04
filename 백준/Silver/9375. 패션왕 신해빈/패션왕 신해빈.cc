#include <iostream>
#include <map>

using namespace std;
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		
		map<string, int> M;

		for (int i = 0; i < m; i++)
		{
			string s, ss;
			cin >> s >> ss;

			M[ss]++;
		}

		int Ret = 1;
		for (auto iter : M)
		{
			Ret *= iter.second + 1;
		}

		Ret--;

		cout << Ret << endl;
	}
}
