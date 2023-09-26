#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <memory.h>

using namespace std;
bool Nums[10]{};
int NumCount[10]{};         // 중복 판별용 배열
void ResetCount(string numbers)
{
    memset(NumCount, 0, sizeof(NumCount));

    // Numbers에 등장한 수의 횟수 체크
    for (int i = 0; i < numbers.size(); i++)
    {
        int num = numbers[i] - '0';
        NumCount[num]++;
    }
}

bool IsPrime(int n)
{
    if (n < 2)
        return false;

    int Limit = sqrt(n);

    for (int i = 2; i <= Limit; ++i)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int solution(string numbers) {
    int answer = 0;

    // Numbers에 등장한 숫자 기록
    for (int i = 0; i < numbers.size(); i++)
    {
        int number = numbers[i] - '0';

        if(!Nums[number])
            Nums[number] = true;
    }

    // 문자열 내림차순 정렬
    sort(numbers.begin(), numbers.end(), greater<int>());

    // 정수 변환해서 최대 경우의 수 뽑기
    int ICount = stoi(numbers);
    
    ResetCount(numbers);
    
    // 최대 경우의 수까지 돌면서 numbers가 한개 포함 or 부분 포함 or 모두 포함된 수를 찾은 뒤 소수 판별
    for (int i = 2; i <= ICount; i++)
    {
        bool IsNum = false;
        string s = to_string(i);

        for (int j = 0; j < s.size(); j++)
        {
            int num = s[j] - '0';
            // Numbers에 등장했던 숫자가 아니라면 continue
            if (false == Nums[num])
            {
                IsNum = false;
                break;
            }

            // 전부 사용한 숫자라면 continue
            if (NumCount[num] == 0)
            {
                IsNum = false;
                break;
            }

            IsNum = true;
            NumCount[num]--;
        }

        // 판별이 끝나면 카운트 초기화
        ResetCount(numbers);

        // Numbers에 등장한 숫자 조합이라면 소수 판별
        if (IsNum)
        {
            int P = stoi(s);

            if (IsPrime(P))
                answer++;
        }
    }

    return answer;
}
