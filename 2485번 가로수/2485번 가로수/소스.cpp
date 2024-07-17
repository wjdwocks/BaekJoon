#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	int arr[100000] = { 0, };
	int term = 1000000000;
	for (int i = 0; i < N; i++)
	{
		std::cin >> arr[i];
		if (i > 0)
		{
			if (term > arr[i] - arr[i - 1])
			{
				term = arr[i] - arr[i - 1]; // 가장 작은 간격을 알아내야함.
				continue;
			}
		}
	}

	int cursor = 1;
	int result = 0;
	int i = 1;
	while (cursor <= N-1)
	{
		if (arr[0] + (term * i) == arr[cursor])
			cursor++;
		else if (arr[0] + (term * i) < arr[cursor])
			result++;
		else
		{
			term--;
			cursor = 1;
			result = 0;
			i = 1;
			continue;
		}
		i++;
	}
	std::cout << result;

}