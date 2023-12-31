#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> A = { 1, 2, 3, 4, 5 };  
    vector<int> B = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> C = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    int IdxA = 0;
    int IdxB = 0;
    int IdxC = 0;

    vector<int> Counts(3);

    for (int i = 0; i < answers.size(); i++)
    {
        if (A[IdxA] == answers[i])
          Counts[0]++;

        if (B[IdxB] == answers[i])
          Counts[1]++;

        if (C[IdxC] == answers[i])
          Counts[2]++;

        IdxA = (IdxA + 1) % A.size();
        IdxB = (IdxB + 1) % B.size();
        IdxC = (IdxC + 1) % C.size();
    }

    int Max = *max_element(Counts.begin(), Counts.end());

    for (int i = 0; i < 3; i++)
    {
        if (Max == Counts[i])
          answer.push_back(i + 1);
    }

    if (answer.size() > 1)
        sort(answer.begin(), answer.end());

    return answer;
}