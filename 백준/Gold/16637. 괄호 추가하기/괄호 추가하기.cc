#include <iostream>
#include <vector>

using namespace std;

int ans = -987654321;
int n; 
char c;
vector<int> nums;
vector<char> signs;

int Func(char a, int b, int c)
{
	if (a == '*')
		return b * c;
	else if (a == '+')
		return b + c;
	else if (a == '-')
		return b - c;

	return 0;
}

// here == 현재 인덱스
// num == 누적 값
void go(int here, int num)
{
	// 끝에 도달했다면 최대값 계산 후 리턴
	if (here == nums.size() - 1)
	{
		ans = max(ans, num);
		return;
	}

	// 누적 값을 매개 변수로 넘겨서 다시 누적 값 계산
	go(here + 1, Func(signs[here], num, nums[here + 1]));

	// 끝에 도달했다면, 현재 리턴된 인덱스까지의 누적 결과 + 현재 인덱스부터 한 쌍의 연산 결과를 연산
	// 인덱스 오버플로우 체크
	if (here + 2 <= nums.size() - 1)
	{
		// 한 쌍의 연산 결과 저장
		int tmp = Func(signs[here + 1], nums[here + 1], nums[here + 2]);
		// 앞 부분 누적 결과와 tmp 연산
		go(here + 2, Func(signs[here], num, tmp));
	}

	return;
}

int main() 
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> c;

		if (i & 1)
			signs.push_back(c);
		else
			nums.push_back(c - '0');
	}

	// 0부터 재귀 시작
	go(0, nums[0]);

	cout << ans << "\n";
}