#include <iostream>

using namespace std;
int main()
{
	int Alpha[26]{};	// 26개

	// 알파벳 소문자로만 이루어진 문자열 입력
	string s;
	cin >> s;

	// 각 알파벳이 단어에 몇개 있는지 출력
	for (int i = 0; i < s.size(); i++)
	{
		Alpha[s[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << Alpha[i] << ' ';
	}
}