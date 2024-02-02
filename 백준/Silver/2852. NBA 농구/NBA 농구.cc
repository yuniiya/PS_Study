#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int n;
int t;
string wt, prevTime;
int ACnt, BCnt;
int AAns, BAns;

void Print(int a)
{
	int m = a / 60;
	int s = a % 60;

	cout << setw(2) << setfill('0') << m << ":" << setw(2) << setfill('0') << s << "\n";
}

int ChangeToInt(string s)
{
	return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
}

void go(int& Ans, string CurTime)
{
	Ans += ChangeToInt(CurTime) - ChangeToInt(prevTime);
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> t >> wt;

		if (ACnt > BCnt)
		{
			go(AAns, wt);
		}
		else if (ACnt < BCnt)
		{
			go(BAns, wt);
		}

		t == 1 ? ACnt++ : BCnt++;
		prevTime = wt;
	}

	if (ACnt> BCnt)
	{
		go(AAns, "48:00");
	}
	else if(ACnt < BCnt)
	{
		go(BAns, "48:00");
	}

	Print(AAns);
	Print(BAns);
}