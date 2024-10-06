#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

using namespace std;

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	list<int> L;
	vector<int> V;

	for (int i = 1; i <= n; i++)
	{
		L.push_back(i);
	}

	list<int>::iterator iter = L.begin();
	advance(iter, k - 1);

	while (!L.empty())
	{
		V.push_back(*iter);
		iter = L.erase(iter);

		if (L.empty())
			break;
		
		for (int i = 0; i < k - 1; i++)
		{
			if (iter == L.end())
			{
				iter = L.begin();
			}

			iter++;
		}

		if (iter == L.end())
		{
			iter = L.begin();
		}
	}

	cout << '<';
	for (int i = 0; i < (int)V.size() - 1; i++)
	{
		cout << V[i] << ", ";
	}
	cout << V.back() << '>';
}