#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <stack>

using namespace std;

int n, a;
vector<char> sign;
int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> target;
	stack<int> order;

	vector<int> rev;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;

		rev.push_back(a);
	}

	reverse(rev.begin(), rev.end());

	// 거꾸로
	for (int i : rev)
	{
		target.push(i);
	}

	int i = 1;
	while (i <= n)
	{
		if (order.empty()) 
		{
			order.push(i);
			sign.push_back('+');

			i++;
		}
		else
		{
			if (order.top() < target.top())
			{
				order.push(i);
				sign.push_back('+');

				i++;
			}
			else
			{
				order.pop();
				target.pop();
				sign.push_back('-');
			}
		}
	}

	if (target.size() == order.size())
	{
		while (!order.empty())
		{
			if (order.top() == target.top())
			{
				order.pop();
				target.pop();

				sign.push_back('-');
			}
			else
			{
				break;
			}
		}
	}

	if (!order.empty())
	{
		cout << "NO";
	}
	else
	{
		for (char e : sign)
		{
			cout << e << '\n';
		}
	}
}