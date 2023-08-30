#include <iostream>
#include <vector>
using namespace std;

const int TURN_LEFT = 0;
const int TURN_RIGHT = 1;

int DirX[4] = { 1, 0, -1, 0 };
int DirY[4] = { 0, 1, 0, -1 };

struct SCommand
{
	string Command;
	int D;
};

int main()
{
	int Result = 0;
	int m, n;
	int X = 0, Y = 0;
	cin >> m >> n;

	vector<SCommand> Commands;

	// 명령어 받기
	for (int i = 0; i < n; i++)
	{
		SCommand Temp;
		string s;
		int a;

		cin >> s >> a;
		Temp.Command = s;
		Temp.D = a;

		Commands.push_back(Temp);
	}

	// 현재 방향
	int CurDir = 0;
	int dx = 0, dy = 0;
	for (int i = 0; i < n; i++)
	{
		if (Commands[i].Command == "MOVE")
		{
			// 현재 방향으로 D만큼 이동
			// 0이면 상쇄
			dx = X + DirX[CurDir] * Commands[i].D;
			dy = Y + DirY[CurDir] * Commands[i].D;
		}
		else if (Commands[i].Command == "TURN")
		{
			if (Commands[i].D == TURN_LEFT)
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
	}

	if (Result == -1)
		cout << Result << endl;
	else
		cout << X << " " << -Y << endl;
}

