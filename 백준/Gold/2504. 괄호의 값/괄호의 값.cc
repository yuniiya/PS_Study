#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

stack<char> st;
string s;
int ans, depth = 1;	// 괄호의 중첩 값을 나타낸다.
int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	for (int i = 0; i < s[i]; i++)
	{
		if (s[i] == '(')
		{
			st.push(s[i]);
			depth *= 2;
		}
		else if (s[i] == '[')
		{
			st.push(s[i]);
			depth *= 3;
		}
		else
		{
			if (s[i] == ')')
			{
				// 괄호 쌍이 안 맞을 경우
				if (st.empty() || st.top() != '(')
				{
					ans = 0;
					break;
				}

				if (s[i - 1] == '(')
				{
					// ()일 경우 현재까지의 괄호 쌍 값을 누적한다.
					// depth는 현재까지의 괄호 쌍의 최종 계산 값을 나타낸다.
					ans += depth;
				}

				// 닫는 괄호일 경우 괄호 중첩을 되돌린다.
				depth /= 2;
				st.pop();
			}
			else if (s[i] == ']')
			{
				if (st.empty() || st.top() != '[')
				{
					ans = 0;
					break;
				}

				if (s[i - 1] == '[')
				{
					ans += depth;
				}

				depth /= 3;
				st.pop();
			}
		}
	}

	if (!st.empty())
	{
		ans = 0;
	}

	cout << ans;
}