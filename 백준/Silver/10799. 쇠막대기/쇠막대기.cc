#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

stack<char> st;
string s;
int ans;
int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	for (int i = 0; i < (int)s.size(); i++)
	{
		if (s[i] == '(')
		{
			st.push(s[i]);
		}
		else
		{
			st.pop();

			// 실수로 레이저를 넣었다면 쇠막대기를 자른다
			if (s[i - 1] == '(')
			{
				ans += st.size();
			}
			else
			{
				// 쇠막대기의 끝이라면 끝 부분을 하나 더한다
				ans++;
			}
		}
	}

	cout << ans;
}