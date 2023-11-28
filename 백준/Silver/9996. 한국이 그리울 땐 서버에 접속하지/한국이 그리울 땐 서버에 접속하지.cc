#include <iostream>
#include <string>

using namespace std;
pair<string, string> P;
int main()
{
	// 1. 입력받은 문자열을 *을 기준으로 두 부분으로 나눈다.
	int n;
	string s;

	cin >> n;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '*')
		{
			P.second = s.substr(i + 1, s.size() - i);
			break;
		}

		P.first += s[i];
	}

	for (int i = 0; i < n; i++)
	{
		string Input;
		cin >> Input;

		if (s.size() - 1 > Input.size())
		{
			cout << "NE" << "\n";
		}
		else if (P.first == Input.substr(0, P.first.size()) && P.second == Input.substr(Input.size() - P.second.size()))
		{
			cout << "DA" << "\n";
		}
		else
		{
			cout << "NE" << "\n";
		}
	}
}