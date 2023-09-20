#include <iostream>
#include <string>

using namespace std;

int InputArray[27]{};
// a b c d e f g h i j 
// k l m n o p q r s t
// u v w x y z 
int main()
{
	int n;
	string Input;
	cin >> n >> Input;

	for (int i = 0; i < Input.size(); i++)
	{
		InputArray[Input[i] - 'A']++;
	}

	int Count = 0;

	for (int i = 0; i < n - 1; i++)
	{
		int WordArray[26]{};

		string s;
		cin >> s;

		// 길이가 1보다 크게 차이나는지 확인
		if (s.size() < Input.size() - 1 || s.size() > Input.size() + 1)
		{
			continue;
		}
		else 
		{
			// 길이가 같거나, 1 이하로 차이날 때만 비슷한 단어의 가능성이 있음. 
			// 
			// 알파벳의 등장 횟수 체크
			for (int j = 0; j < s.size(); j++)
			{
				WordArray[s[j] - 'A']++;
			}

			bool Flag = false;

			// Input과 Word배열의 단어 비교
			for (int j = 0; j < 26; j++)
			{
				// 같은 단어 + 같은 개수 + (다른 구성or같은 구성) 이라면
				if (InputArray[j] == WordArray[j])
				{
					if (InputArray[j] != 0 && WordArray[j] != 0)
					{
						Flag = true;

					}
				}
				else
				{
					Flag = true;

					// 같은 단어의 개수가 다르다면, 1개를 더하거나/뺴거나/교체했을 때 비슷한 단어가 될 가능성이 있는지 확인
					// 1. Input 개수가 1개 더 많다면
					if (InputArray[j] - WordArray[j] == 1)
					{
						// 길이가 같다면, Input과 개수가 다른 단어를 다른 단어로 교체
						if (Input.size() == s.size())
						{
							for (int k = 0; k < 26; k++)
							{
								if (j == k) continue;

								if (InputArray[k] != WordArray[k])
								{
									WordArray[j]++;
									WordArray[k]--;
									break;
								}
							}
						}
						else if (Input.size() > s.size())
						{
							// Input이 더 길다면 s에서 1개 더 적은 글자 추가
							WordArray[j]++;
						}
						else if (Input.size() < s.size())
						{
							// Input이 더 짧다면 비슷한 단어 불가능 
							Flag = false;
						}
					}
					// 2. Word의 개수가 1개 더 많다면
					else if (WordArray[j] - InputArray[j] == 1)
					{
						// 길이가 같다면 교체
						if (Input.size() == s.size())
						{
							for (int k = 0; k < 26; k++)
							{
								if (j == k) continue;

								if (InputArray[k] != WordArray[k])
								{
									WordArray[j]--;
									WordArray[k]++;
									break;
								}
							}
						}
						else if (Input.size() > s.size())
						{
							// Input이 더 길다면 s에서 1개 더 많은 글자 삭제
							Flag = false;
						}
						else if (Input.size() < s.size())
						{
							WordArray[j]--;
						}
					}

					// 비슷한 단어 가능성이 있다면
					if (Flag)
					{
						// 구성 다시 확인
						for (int k = 0; k < 26; k++)
						{
							if (InputArray[k] != WordArray[k])
							{
								Flag = false;
								break;
							}
						}
					}

					if (!Flag)
						break;
				}
			}

			// 비슷한 단어라면 Count++
			if (Flag)
			{
				Count++;
			}
		}
	}

	cout << Count;
}