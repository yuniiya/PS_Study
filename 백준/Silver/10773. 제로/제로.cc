#include <iostream>
#include <stack>

using namespace std;

int k, n, ans;
int main(void) 
{
	stack<int> st;

	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> n;

		if (n == 0 && !st.empty())
		{
			st.pop();
			
			continue;
		}

		st.push(n);
	}

	while (!st.empty())
	{
		ans += st.top();
		st.pop();
	}

	cout << ans;
}