#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    
    for(char c : s)
    {
        if(st.empty())
        {
            st.push(c);
        }
        else
        {
            if(st.top() == '(' && c == ')')
            {
                st.pop();
                continue;
            }
            
            st.push(c);
        }
    }
    
    if(!st.empty())
        answer = false;
    
    return answer;
}