#include <iostream>

using namespace std;
int main() 
{
	int Count = 0;
	int n;
	cin >> n;

	int Start = -1;
	int Target = 0;

	int Units = n % 10;						
	int Tens = n / 10;						

	while (Start != n)
	{	
		Target = Units + Tens;					
		Start = (Units * 10) + (Target % 10);	

		Units = Start % 10;						
		Tens = Start / 10;						

		Count++;
	}

	cout << Count;

}
