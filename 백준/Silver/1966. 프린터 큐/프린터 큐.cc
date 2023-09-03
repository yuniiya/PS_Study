#include <iostream>
#include <queue>

using namespace std;
int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		priority_queue<int> PQ;
		queue<pair<int, int>> Q;

		int Result = 0;

		// 문서의 개수, 몇번쨰로 입력되었는지 궁금한 문서의 인덱스
		int n, Idx;
		cin >> n >> Idx;

		for (int j = 0; j < n; j++)
		{
			// 문서 n개의 중요도
			int a;
			cin >> a;

			Q.push(make_pair(a, j));	// 중요도, 인덱스
			PQ.push(a);					// 중요도(내림차순 정렬)
		}

		// 몇번째로 인쇄되는지
		while (!Q.empty())
		{
			int first = Q.front().first;	// 가장 앞쪽 문서의 중요도
			int second = Q.front().second;	// 순서 인덱스
			Q.pop();
			
			// 가장 높은 우선순위보다 중요도가 작다면
			if (first < PQ.top())
			{
				// 맨 뒤로 보낸다S
				Q.push(make_pair(first, second));
			}
			else
			{
				// 크다면 인쇄
				Result++;
				PQ.pop();

				// 찾던 숫자라면
				if (Idx == second)
				{
					cout << Result << endl;
					break;
				}
			}
		}
	}
}

// PQ 4 3 2 1 
// a b c d 1 2 3 4
// b c d a 2 3 4 1
// c d a b 3 4 1 2
// d a b c 4 1 2 3   // d출력
// a b c 1 2 3