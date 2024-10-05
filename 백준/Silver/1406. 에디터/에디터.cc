#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int Max = 1000005;
char dat[Max];
int pre[Max], nxt[Max];
int unused = 1;

void insert(int addr, char num)
{
	dat[unused] = num;
	nxt[unused] = nxt[addr];
	pre[unused] = addr;

	if (nxt[addr] != -1)
	{
		pre[nxt[addr]] = unused;
	}

	nxt[addr] = unused;

	unused++;
}

void erase(int addr)
{
	if (pre[addr] != -1)
	{
		nxt[pre[addr]] = nxt[addr];
	}

	if (nxt[addr] != -1)
	{
		pre[nxt[addr]] = pre[addr];
	}
}

void traverse()
{
	int cur = nxt[0];

	while (cur != -1)
	{
		cout << dat[cur];
		cur = nxt[cur];
	}
}

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(pre, pre + Max, -1);
	fill(nxt, nxt + Max, -1);

	string s;
	int a;

	cin >> s;

	int cursor = 0;
	for (char c : s)
	{
		insert(cursor, c);
		cursor++;
	}
		
	cin >> a;
	while (a--)
	{
		char c;
		cin >> c;

		if (c == 'L')
		{
			if (pre[cursor] != -1)
				cursor = pre[cursor];
		}
		else if (c == 'D')
		{
			if (nxt[cursor] != -1)
				cursor = nxt[cursor];
		}
		else if (c == 'B')
		{
			if (cursor != 0 && pre[cursor] != -1)
			{
				erase(cursor);
				cursor = pre[cursor];
			}
		}
		else if (c == 'P')
		{
			char t;
			cin >> t;

			insert(cursor, t);

			cursor = nxt[cursor];
		}
	}

	traverse();
}