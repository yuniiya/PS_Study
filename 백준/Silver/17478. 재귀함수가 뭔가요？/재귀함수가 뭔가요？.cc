#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

using namespace std;

int n;

void printUnderbar(int x)
{
	if (x == -1) return;

	int tmp = x  * 4;

	while (tmp--)
	{
		cout << "_";
	}
}

void print(string s, int x = -1)
{
	printUnderbar(x);
	cout << s << '\n';
}

void func(int t)
{
	if (t == n)
	{
		print("\"재귀함수가 뭔가요?\"", t);
		print("\"재귀함수는 자기 자신을 호출하는 함수라네\"", t);
		print("라고 답변하였지.", t);

		return;
	}

	print("\"재귀함수가 뭔가요?\"", t);
	print("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.", t);
	print("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.", t);
	print("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"", t);
	func(t + 1);
	print("라고 답변하였지.", t);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	print("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.");
	func(0);

}