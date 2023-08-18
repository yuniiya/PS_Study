#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int main() 
{
	string n;
	string Result;
	
	cin >> n;

	for (int i = 0; i < n.size(); i++)
	{
		int Num = n[i] - '0';
		vector<int> V;

		while (Num > 0)
		{
			int a = Num % 2;
			Num /= 2;

			V.push_back(a);
		}
		
		if (V.size() < 3 && i > 0)
		{
			int Size = (int)V.size();
			for (int j = 0; j < 3 - Size; j++)
			{
				V.push_back(0);
			}
		}

		reverse(V.begin(), V.end());

		for (int j = 0; j < V.size(); j++)
		{
			Result += to_string(V[j]);
		}
	}

	if (Result == "")
		cout << "0";
	else
		cout << Result;
}

