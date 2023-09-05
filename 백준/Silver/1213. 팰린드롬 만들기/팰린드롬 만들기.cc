#include <iostream>
#include <string>
#include <algorithm>

const int ALPHA_COUNT = 26;
using namespace std;
int main()
{
    int Alpha[ALPHA_COUNT]{};

    string Odd = "";
    string Even = "";
    string Result = "";
    string Name;

    cin >> Name;

    for (int i = 0; i < (int)Name.length(); i++)
    {
        // 알파벳에 상응하는 인덱스에 개수 저장
        Alpha[Name[i] - 'A']++;
    }

    int OddCount = 0;
    int Idx = -1;
    for (int i = 0; i < (int)Name.length(); i++)
    {
        // 알파벳 인덱스에 저장된 등장 횟수가 홀수인지 짝수인지
        if (Alpha[Name[i] - 'A'] % 2 == 0)
        {
            Even += Name[i];
        }
        else
        {
            bool IsFlag = false;

            if (Odd.size() > 0)
            {
                for (int j = 0; j < (int)Odd.length(); j++)
                {
                    if (Odd[j] == Name[i])
                    {
                        IsFlag = true;
                    }
                }
            }

            if (!IsFlag)
            {
                Idx = Name[i] - 'A';
                OddCount++;
            }
            Odd += Name[i];
        }
    }

    if (OddCount > 1)
    {
        cout << "I'm Sorry Hansoo" << endl;
    }
    else
    {
        for (int i = 0; i < ALPHA_COUNT; i++)
        {
            if (Alpha[i] != 0)
            {
                // 등장횟수 / 2 번 만큼 더하기
                for (int j = 0; j < Alpha[i] / 2; j++)
                {
                    Result += i + 'A';
                }
            }
        }
        string Temp = Result;

        reverse(Temp.begin(), Temp.end());

        // 홀수번 등장한 알파벳이 있다면 
        if (-1 != Idx)
        {
            Result += Idx + 'A';
        }

        Result += Temp;
        cout << Result << endl;
    }
}