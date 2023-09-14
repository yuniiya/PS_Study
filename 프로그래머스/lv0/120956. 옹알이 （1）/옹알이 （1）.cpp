#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (int i = 0; i < babbling.size(); ++i)
    {
        int Count = 0;
        // vector 내 한 문자열 요소의 길이만큼
        for (int j = 0; j < babbling[i].size(); ++j)
        {
            bool Flag = false;
            string s = babbling[i];

            if (s.substr(j, 3) == "aya")
            {
                j += 2;
            }
            else if (s.substr(j, 2) == "ye")
            {
                j++;
            }
            else if (s.substr(j, 3) == "woo")
            {
                j += 2;
            }
            else if (s.substr(j, 2) == "ma")
            {
                j++;
            }
            else
            {
                Count = 0;
                break;
            }

            if (!Flag)
                Count++;
        }

        if (Count != 0)
            answer++;
    }
    
    return answer;
}