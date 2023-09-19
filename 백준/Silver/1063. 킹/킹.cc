#include <iostream>
#include <string>

using namespace std;
const int X = 0;
const int Y = 1;
int main()
{
    // 킹의 위치, 돌의 위치, 움직이는 횟수
    string King, Rock;
    int n;

    cin >> King >> Rock >> n;

    // 행 열 변환
    int KingLocation[2] = { 9 - (King[1] - '0'), King[0] - 64};
    int RockLocation[2] = { 9 - (Rock[1] - '0'), Rock[0] - 64 };

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        int NextKingX = 0;
        int NextKingY = 0;
        int DirX = 0;
        int DirY = 0;

        if (s == "R")
        {
            DirY++;
        }
        else if (s == "L")
        {
            DirY--;
        }
        else if (s == "B")
        {
            DirX++;
        }
        else if (s == "T")
        {
            DirX--;
        }
        else if (s == "RT")
        {
            DirY++;
            DirX--;
        }
        else if (s == "LT")
        {
            DirY--;
            DirX--;
        }
        else if (s == "RB")
        {
            DirY++;
            DirX++;
        }
        else if (s == "LB")
        {
            DirY--;
            DirX++;
        }

        // 킹 위치 이동
        NextKingX = KingLocation[X] + DirX;
        NextKingY = KingLocation[Y] + DirY;

        // 범위 체크
        if (NextKingX < 1 || NextKingX > 8 || NextKingY < 1 || NextKingY > 8)
            continue;

        KingLocation[X] = NextKingX;
        KingLocation[Y] = NextKingY;

        // 킹과 돌 위치 비교 후, 돌의 위치와 같다면 킹 이동방향으로 돌 이동
        if (NextKingX == RockLocation[X] && NextKingY == RockLocation[Y])
        {
            int NextRockX = RockLocation[X] + DirX;
            int NextRockY = RockLocation[Y] + DirY;

            // 돌 위치가 범위를 벗어났다면 킹 위치 되돌리기
            if (NextRockX < 1 || NextRockX > 8 || NextRockY < 1 || NextRockY > 8)
            {
                KingLocation[X] = NextKingX - DirX;
                KingLocation[Y] = NextKingY - DirY;
                continue;
            }

            RockLocation[X] = NextRockX;
            RockLocation[Y] = NextRockY;
        }
    }

    cout << (char)(KingLocation[1] + 64) << (char)((9 - KingLocation[0]) + '0') << endl;
    cout << (char)(RockLocation[1] + 64) << (char)((9 - RockLocation[0]) + '0') << endl;
}