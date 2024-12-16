#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

const int MX = 2000004;
int dat[MX];
int head, tail = 0;

int empty()
{
	if (head == tail)
		return 1;

	return 0;
}

void push(int x)
{
	dat[tail++] = x;

	if (tail == MX)
	{
		tail = 0;
	}
}

int pop()
{
	if (empty())
		return -1;

	int ret = dat[head];

	if (++head == MX)
	{
		head = 0;
	}

	return ret;
}

int front()
{
	if (empty())
		return -1;

	return dat[head];
}

int back() 
{
	if (empty())
		return -1;

	return dat[tail - 1];
}

int size()
{
	if (tail - head >= 0)
		return tail - head;
	else
		return MX - head - 1;
}

int n, a;
string s;
int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s;

		if (s == "push")
		{
			cin >> a;

			push(a);
		}
		else if (s == "pop")
		{
			cout << pop() << '\n';
		}
		else if (s == "size")
		{
			cout << size() << '\n';
		}
		else if (s == "empty")
		{
			cout << empty() << '\n';
		}
		else if (s == "front")
		{
			cout << front() << '\n';
		}
		else if (s == "back")
		{
			cout << back() << '\n';
		}
	}
}