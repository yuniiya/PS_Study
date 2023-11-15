#include <iostream>
#include <vector>

using namespace std;

int n, TargetCount;
int Count = 0;
int Number = 0;
bool Succeess = false;

vector<int> Arrays;
vector<int> Temp;

void Merge(int Start, int End)
{
	int Mid = (Start + End) / 2;

	int i = Start;
	int j = Mid + 1;
	int k = Start;

	while (i <= Mid && j <= End)
	{
		if (Arrays[i] <= Arrays[j])
		{
			Temp[k++] = Arrays[i++];
		}
		else
		{
			Temp[k++] = Arrays[j++];
		}
	}

	int Tmp = i > Mid ? j : i;

	while (k <= End)
	{
		Temp[k++] = Arrays[Tmp++];
	}
	
	for (int t = Start; t <= End; t++)
	{
		Arrays[t] = Temp[t];
		Count++;

		if (Count == TargetCount)
		{
			Number = Temp[t];
			Succeess = true;
		}
	}
}

void MergeSort(int Start, int End)
{
	if (Start < End)
	{
		int Mid = (Start + End) / 2;

		MergeSort(Start, Mid);
		MergeSort(Mid + 1, End);

		Merge(Start, End);
	}
}

int main()
{
	cin >> n >> TargetCount;

	Arrays.resize(n);
	Temp.resize(n);

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		Arrays[i] = a;
	}

	MergeSort(0,  n - 1);

	if (Succeess)
	{
		cout << Number;
	}
	else
	{
		cout << -1;
	}
}