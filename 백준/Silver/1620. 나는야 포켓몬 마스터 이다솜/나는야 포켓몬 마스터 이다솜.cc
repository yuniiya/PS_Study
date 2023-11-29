#include <iostream>
#include <string>
#include <map>

using namespace std;
string N[100004];
map<string, int> M;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;

		M.insert({ s, i });
		N[i] = s;
	}

	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;

		// 알파벳 -> 번호 출력
		if (s[0] >= 'A' && s[0] <= 'Z')
		{
			cout << M.at(s) << "\n";
		}
		else
		{
			// 숫자 -> 알파벳 출력
			int Idx = stoi(s);
			cout << N[Idx] << "\n";
		}
	}
}