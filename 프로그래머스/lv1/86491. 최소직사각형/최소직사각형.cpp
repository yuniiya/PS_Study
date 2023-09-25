#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int Y = 0;    // 가로
    int X = 0;    // 세로

    // 이전 가로 길이 - 현재 세로 길이 비교 후, 현재 세로 길이가 더 길다면 TmpX에 저장
    // 이전 세로 길이 - 현재 가로 길이 비교 후, 현재 가로 길이가 더 짧다면 TmpY에 저장

    for(int i = 0; i < sizes.size(); i++)
    {
        int TmpY = sizes[i][0];     // 가로
        int TmpX = sizes[i][1];     // 세로
    
        for(int j = 0; j < sizes[i].size(); j++)    
        {
            // 가로 - 세로 비교 
            TmpY = max(TmpY, sizes[i][1]);     

            if(X * TmpY >= X * Y)
                Y = TmpY;
            
            // 세로 - 가로 길이 비교 
            TmpX = min(TmpX, sizes[i][0]);

            if(TmpX * Y >= X * Y)
                X = TmpX;
        }
    }
    
    answer = X * Y;
    
    return answer;
}