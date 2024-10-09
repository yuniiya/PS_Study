#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

bool empty()
{
	if (pos - 1 < 0)
		return true;

	return false;
}

void push(int x)
{
	dat[pos++] = x;
}

int pop() 
{
	if (!empty())
	{
		pos--;
		
		return dat[pos];
	}

	return -1;
}

int top() 
{
	if (!empty())
		return dat[pos - 1];

	return -1;
}

int size()
{
	return pos;
}

int main(void) 
{
	int a;
	cin >> a;

	for (int i = 0; i < a; i++)
	{
		string s;
		cin >> s;

		if (s == "push")
		{
			int i;
			cin >> i;

			push(i);
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
		else if (s == "top")
		{
			cout << top() << '\n';
		}
	}
}