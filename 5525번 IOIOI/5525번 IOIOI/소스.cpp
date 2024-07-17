#include <iostream>

int main()
{
	int N, M;
	std::cin >> N;
	std::cin >> M;
	std::string S;
	std::cin >> S;
	int length = 0;
	bool IOI = false;
	int result = 0;
	// 문자열을 검사해서 IOIOIOI가 연속으로 나오면 그거를 캐치하고, 처음과 끝의 길이를 봐서 그거랑 N이랑 비교해서 개수를 전체에 더하고 반복.
	for (int i = 0; i <= M; ++i)
	{
		if (IOI == false && S[i] == 'I') // IOI가 이어지지 않고 있고, 처음으로 I가 나오면
		{
			IOI = true;
			length++;
		}
		else if (IOI == true && S[i] != S[i - 1] && S[i] != NULL)
			length++;
		else if (IOI == true && S[i] == S[i - 1] && S[i-1] == 'O')
		{
			length -= 1;
			length /= 2; // 이 때 length가 O의 개수. 
			int temp = length + 1 - N;
			if (temp < 0)
				temp = 0;
			result += temp;
			length = 0;
			IOI = false;
		}
		else if (IOI == true && S[i] == S[i - 1] && S[i-1] == 'I')
		{
			length /= 2;
			int temp = length + 1 - N;
			if (temp < 0)
				temp = 0;
			result += temp;
			length = 1;
		}
		else if (IOI == true && S[i] == NULL && S[i-1] == 'I')
		{
			length /= 2;
			int temp = length + 1 - N;
			if (temp < 0)
				temp = 0;
			result += temp;
			length = 0;
			IOI = false;
		}
		else if (IOI == true && S[i] == NULL && S[i - 1] == 'O')
		{
			length -= 1;
			length /= 2;
			int temp = length + 1 - N;
			if (temp < 0)
				temp = 0;
			result += temp;
			length = 0;
			IOI = false;
		}
	}
	std::cout << result;
}