#include <iostream>
#include <cmath>



int main()
{
	int T;
	std::cin >> T;
	int* arr = (int*)calloc(1000001, sizeof(int));
	for (int i = 2; i < 1000001; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = 2 * i; j < 1000001; j += i) // j를 제외한 j의 배수들을 다 1으로 넣음.
			{
				arr[j] = 1;
			}
		}
	}
	
	while (T--)
	{
		int N, result = 0;
		std::cin >> N;
		for (int i = 2; i <= N / 2; i++)
		{
			if (arr[i] == 0 && arr[N - i] == 0)
				result++;
		}
		std::cout << result << '\n';
	}
}