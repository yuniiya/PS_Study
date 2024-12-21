#include <iostream>

using namespace std;

const int MX = 10004;
const int MAX_IDX = 2 * MX;
int dat[2 * MX + 1];
int head = MX, tail = MX;

bool empty()
{
	if (head == tail)
		return true;

	return false;
}

void push_front(int x)
{
	if (head <= 0)
		return;

	dat[--head] = x;
}

void push_back(int x)
{
	if (tail >= MAX_IDX)
		return;

	dat[tail++] = x;
}

int pop_front()
{
	if (empty())
		return -1;

	return dat[head++];
}

int pop_back()
{
	if (empty())
		return -1;

	return dat[--tail];
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
	return tail - head;
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

		if (s == "push_front")
		{
			cin >> a;
			push_front(a);
		}
		else if (s == "push_back")
		{
			cin >> a;
			push_back(a);
		}
		else if (s == "pop_front")
		{
			cout << pop_front() << '\n';
		}
		else if (s == "pop_back")
		{
			cout << pop_back() << '\n';
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