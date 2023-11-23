#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Dwarfs;
vector<int> CombiArray;
vector<int> SaveDwarfs;
int Sum = 0;
void Combi(int Index, vector<int> CombiArray)
{
	if (CombiArray.size() == 7)
	{
		for (int i = 0; i < 7; i++)
		{
			Sum += Dwarfs[CombiArray[i]];
		}

		return;
	}

	for (int i = Index + 1; i < 9; i++)
	{
		CombiArray.push_back(i);
		Combi(i, CombiArray);

		if (100 == Sum && SaveDwarfs.empty())
		{
			for (int j = 0; j < 7; j++)
			{
				SaveDwarfs.push_back(Dwarfs[CombiArray[j]]);
			}

			break;
		}

		Sum = 0;
		CombiArray.pop_back();
	}

}

int main()
{
	// 난쟁이의 수가 9줄에 걸쳐 입력
	for (int i = 0; i < 9; i++)
	{
		int a;
		cin >> a;
		Dwarfs.push_back(a);
	}
	

	// 7번 뽑는 조합을 찾은 뒤, 찾아온 인덱스의 값을 더하기
	// 100이 아니라면 다시 찾기
	Combi(-1, CombiArray);

	// 찾아온 난쟁이의 키를 오름차순으로 출력
	sort(SaveDwarfs.begin(), SaveDwarfs.end());

	for (int i : SaveDwarfs)
	{
		cout << i << '\n';
	}
}