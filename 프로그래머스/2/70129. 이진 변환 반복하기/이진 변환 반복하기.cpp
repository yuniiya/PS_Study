#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> solution(string s) 
{
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    
    while(s != "1")
    {
        answer[0]++;
        answer[1] += (int)s.size();
        
        stringstream sst(s);
        s = "";
        string token = "";
        while(getline(sst, token, '0'))
        {
            s += token;
        }
        
        int len = s.length();
        answer[1] -= len;
        
        string tmp = "";
        
        while(len > 0)
        {
            tmp += to_string((len % 2));
            len /= 2;
        }
        
        reverse(tmp.begin(), tmp.end());
        s = tmp;
    }
   
    return answer;
}