#include <iostream>
#include <stack>
#include <memory.h>

using namespace std;

int n;
int N[1000001], Ans[1000001];
stack<int> st;
int main()
{
	cin >> n;

	memset(Ans, -1, sizeof(Ans));

	for (int i = 0; i < n; i++)
	{
		cin >> N[i];

		while (st.size() && N[st.top()] < N[i])
		{
			Ans[st.top()] = N[i];
			st.pop();
		}

		st.push(i);
	}

	for (int i = 0; i < n; i++)
	{
		cout << Ans[i] << " ";
	}
}