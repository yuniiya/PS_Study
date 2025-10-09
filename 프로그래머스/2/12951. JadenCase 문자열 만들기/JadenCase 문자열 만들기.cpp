#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) 
{
    string answer = "";
    bool bStart = true;
    
    for(int i = 0; i < (int)s.size(); i++)
    {
        if(s[i] == ' ')
        {
            bStart = true;
            continue;
        }
           
        if(bStart)
        {
            if(islower(s[i]))
            {
                s[i] = toupper(s[i]);
            }
            
            bStart = false;
        }
        else
        {
            if(isupper(s[i]))
            {
                s[i] = tolower(s[i]);
            }
        }
    }
    
    answer = s;
    
    return answer;
}