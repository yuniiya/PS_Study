#include <iostream>
#include <vector>

using namespace std;

int Dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };	// 위 오 아래 왼
int main()
{
	int n, Target;
	cin >> n  >> Target;

	int CurX = n / 2 + 1;
	int CurY = CurX;							// 현재 인덱스
	int TargetIdx[2]{};							// 타겟이 위치한 인덱스
	int Num = 0;								// 표에 채울 숫자
	int ChangeCount = 0;						// 방향 전환 횟수
	int Length = 1;								// 전진 범위
	int LenCount = 0;

	vector<vector<int>> Board(n + 1, vector<int>(n + 1, 0));
	int CurDir = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// 채울 숫자
			Num = j + ((i - 1) * n);
			
			// 타깃인지 확인
			if (Target == Num)
			{
				TargetIdx[0] = CurX;
				TargetIdx[1] = CurY;
			}

			// 현재 인덱스에 표 채우기
			Board[CurX][CurY] = Num;
			++LenCount;
		
			// 범위 갱신
			if (ChangeCount == 2)
			{
				++Length;
				ChangeCount = 0;
			}

			// 위치 갱신
			CurX += Dir[CurDir][0];
			CurY += Dir[CurDir][1];

			// 방향 갱신
			if (LenCount == Length)
			{
				CurDir = (++CurDir % 4);
				++ChangeCount;
				LenCount = 0;
			}

		}
	}

	// 표 출력
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << Board[i][j] << ' ';
		}
		
		cout << '\n';
	}

	// 타깃 출력
	cout << TargetIdx[0] << ' ' << TargetIdx[1] << endl;
}