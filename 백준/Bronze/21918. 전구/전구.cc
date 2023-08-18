#include <iostream>
#include <vector>

using namespace std;

struct SCommand
{
	int Command;
	int First;
	int Second;
};

int main(void) 
{
	int n, m;
	cin >> n >> m;
	
	vector<bool> V(n + 1);
	vector<SCommand> Commands;

	for (int i = 1; i < n + 1; i++)
	{
		bool a;
		cin >> a;
		V[i] = a;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		SCommand C;
		C.Command = a;
		C.First = b;
		C.Second = c;

		Commands.push_back(C);
	}

	for (int i = 0; i < Commands.size(); i++)
	{
		int First = Commands[i].First;
		int Second = Commands[i].Second;

		switch (Commands[i].Command)
		{
		case 1:
		{
			V[First] = Second;
		}
			break;
		case 2:	
		{
			for (int j = First; j < Second + 1; j++)
			{
				V[j] = !V[j];
			}
		}
			break;
		case 3:
		{
			for (int j = First; j < Second + 1; j++)
			{
				V[j] = false;
			}
		}
			break;
		case 4:
		{
			for (int j = First; j < Second + 1; j++)
			{
				V[j] = true;
			}
		}
			break;
		}
	}


	for (int i = 1; i < V.size(); i++)
	{
		cout << V[i] << ' ';
	}
}
