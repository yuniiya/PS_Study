#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
#include <map>

using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int n, c, a;
map<int, int> mp;
map<int, int> mp_order;
vector<pair<int, int>> v;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return mp_order[a.first] < mp_order[b.first];
	}

	return a.second > b.second;
}

int main()
{
	cin >> n >> c;

	for (int i = 0; i < n; i++)
	{
		cin >> a;

		mp[a]++;

		if (mp_order[a] == 0)
			mp_order[a] = i + 1;
	}

	for (auto iter : mp)
	{
		v.push_back({ iter.first, iter.second });
	}

	sort(v.begin(), v.end(), cmp);

	for (auto iter : v)
	{
		for (int i = 0; i < iter.second; i++)
		{
			cout << iter.first << " ";
		}
	}
}