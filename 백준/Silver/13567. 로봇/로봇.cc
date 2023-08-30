#include <iostream>
#include <queue>

using namespace std;

const int TURN_LEFT = 0;
const int TURN_RIGHT = 1;

int Dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int main()
{
	int Result = 0;
	int m, n;
	int X = 0, Y = 0;
	cin >> m >> n;

	queue<pair<string, int>> Commands;

	// 명령어 받기
	for (int i = 0; i < n; i++)
	{
		string s;
		int a;
		cin >> s >> a;

		Commands.push(make_pair(s, a));
	}

	// 현재 방향
	int CurDir = 0;
	int dx = 0, dy = 0;


	while (!Commands.empty())
	{
		if (Commands.front().first == "MOVE")
		{
			dx = X + Dir[CurDir][0] * Commands.front().second;
			dy = Y + Dir[CurDir][1] * Commands.front().second;
		}
		else if(Commands.front().first == "TURN")
		{
			if (Commands.front().second == TURN_LEFT)
			{
				// 왼쪽 90도 회전
				if (--CurDir < 0)
				{
					CurDir = 3;
				}

			}
			else
			{
				// 오른쪽 90도 회전
				if (++CurDir > 3)
				{
					CurDir = 0;
				}
			}
		}

		if (dx >= m || dx < 0 || -dy >= m || -dy < 0)
		{
			Result = -1;
			break;
		}

		X = dx;
		Y = dy;
		Commands.pop();
	}

	if (Result == -1)
		cout << Result << endl;
	else
		cout << X << " " << -Y << endl;
}

