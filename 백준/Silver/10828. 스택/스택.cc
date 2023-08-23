#include <iostream>

using namespace std;
const int MAX = 10001;

class Stack
{
public:
	Stack(int _Size)
		: TopIdx(-1)
	{
		Array = new int[_Size];
	}
	
	~Stack()
	{};
	
public:
	int empty()
	{
		if (TopIdx == -1)
		{
			return 1;
		}

		return 0;
	}

	void push(int _x)
	{
		if (TopIdx >= MAX)
			return;

		Array[++TopIdx] = _x;
	}

	int pop()
	{
		if (TopIdx == -1)
		{
			return -1;
		}

		return Array[TopIdx--];
	}

	int size()
	{
		return TopIdx + 1;
	}

	int top()
	{
		if (TopIdx == -1)
		{
			return -1;
		}
		
		return Array[TopIdx];
	}

private:
	int TopIdx;
	int* Array;
};


int main()
{
	int n;
	cin >> n;

	Stack stack(n);

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		// 공백을 기준으로 입력이 끊겼다면, push인지 확인 후 다음 숫자 입력받기 
		if (s == "push")
		{
			int x;
			cin >> x;

			stack.push(x);
		}
		else if(s == "pop")
		{
			cout << stack.pop() << endl;
		}
		else if (s == "size")
		{
			cout << stack.size() << endl;
		}
		else if (s == "empty")
		{
			cout << stack.empty() << endl;
		}
		else if (s == "top")
		{
			cout << stack.top() << endl;
		}
	}
}

