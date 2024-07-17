#include <iostream>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;

	int* arr = new int[N];

	for (int i = 0; i < N; i++)
	{
		std::cin >> arr[i];
	}

	std::sort(arr, arr+N);

	if (N == 1)
	{
		std::cout << arr[0] * arr[0];
		return 0;
	}
	std::cout << arr[0] * arr[N - 1];
}