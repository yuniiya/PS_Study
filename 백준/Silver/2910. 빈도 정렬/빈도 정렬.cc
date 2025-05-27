#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <stack>
#include <memory.h>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n, c, k;
map<int, int> mp_cnt;
map<int, int> mp_order;
vector<int> v;

bool cmp(int a, int b)
{
	if (mp_cnt[a] != mp_cnt[b])
		return mp_cnt[a] > mp_cnt[b];

	return mp_order[a] < mp_order[b];
}

int main()
{
	cin >> n >> c;

	for (int i = 0; i < n; i++)
	{
		cin >> k;

		mp_cnt[k]++;

		if (mp_order[k] == 0)
			mp_order[k] = i + 1;

		v.push_back(k);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i : v)
	{
		cout << i << " ";
	}
}	

