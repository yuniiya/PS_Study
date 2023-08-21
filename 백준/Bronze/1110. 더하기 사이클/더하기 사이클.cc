#include <iostream>

using namespace std;
int main() 
{
	int Count = 0;
	int n;
	cin >> n;

	int Value = -1;
	int Target = 0;

	int Left = n % 10;						
	int Right = n / 10;						

	while (Value != n)
	{	
		Target = Left + Right;
		Value = (Left * 10) + (Target % 10);

		Left = Value % 10;
		Right = Value / 10;

		Count++;
	}

	cout << Count;
}
