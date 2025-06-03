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

int n, m;
int main()
{
	cin >> n;

	int i = 666;
	for (;; i++)
	{
		if (to_string(i).find("666") != string::npos)
			m++;

		if (n == m)
			break;
	}

	cout << i << "\n";
}	

