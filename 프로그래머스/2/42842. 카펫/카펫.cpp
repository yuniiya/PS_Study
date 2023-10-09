#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int W = 0;   // 가로
    int H = 0;   // 세로
    
    int WH = brown + yellow;
    
    for(int i = 3; i <= WH; i++)
    {
        if(WH % i == 0)
        {
            W = i;
            H = WH / i;
            
            if(H < 3 || W < H)
                continue;
            
            // 판별
            if((W - 2) * (H - 2) == yellow)
                break;
        }
    }
    
    answer.push_back(W);
    answer.push_back(H);
        
    return answer;
}