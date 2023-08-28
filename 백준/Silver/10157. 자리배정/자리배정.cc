#include <iostream>
using namespace std;

int Dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
bool Seat[1001][1001]{};
int main()
{
	int c, r, k;
	cin >> c >> r >> k;
	// r행 c열
	
	// 자리 개수보다 번호가 큰 경우
	if (k > c * r)
	{
		cout << 0;
	}
	else
	{
		// 0, 0부터 시작
		int X = r;
		int Y = 0;
		int K = 1;
		int Idx = 0;

		while (K <= k)
		{
			// 현재 X, Y + 방향
			int dx = X + Dir[Idx][0];
			int dy = Y + Dir[Idx][1];

			// 범위를 넘어서거나, 이미 채워진 자리라면 방향 전환
			if (dx < 0 || dx >= r || dy < 0 || dy >= c || Seat[dx][dy] == true)
			{
				Idx = (Idx + 1) % 4;
				continue;
			}
			Seat[dx][dy] = true;
			K++;
			// 현재 X, Y 갱신
			X = dx;
			Y = dy;
		}

		// 문제에서는 1, 1부터이기 때문에 Y + 1 
		cout << Y + 1 << " " << r - X;
	}
}

