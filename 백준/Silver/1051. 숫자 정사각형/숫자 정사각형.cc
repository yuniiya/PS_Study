#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    // n행 m열
    int n, m;
    cin >> n >> m;

    vector<vector<int>> Squares(n, vector<int>(m));
    int Range = min(n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &Squares[i][j]);
        }
    }

    int Result = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int Target = Squares[i][j];
            int x = 0, y = 0;
            int Size = 0;

            int l = i;
            //  타깃이 있는지 검사
            for (int k = j; k < Range + j; k++)
            {
                if (k + 1 >= m || l + 1 >= n)
                    break;

                // 오른쪽 위, 왼쪽 아래 꼭짓점 확인
                // 같은 행 && 같은 열
                if (Squares[l + 1][j] == Target && Squares[i][k + 1] == Target)
                {
                    x = l + 1;
                    y = k + 1;

                    if (Squares[x][y] == Target)
                    {
                        // 크기 계산
                        int Length = x - i + 1;
                        int Temp = Length * Length;

                        Result = max(Result, Temp);
                    }
                }
                l++;
            }

            //// 오른쪽 아래 확인
            //if (x != 0 && y != 0)
            //{
            //   
            //}
        }
    }
    cout << Result;  
}