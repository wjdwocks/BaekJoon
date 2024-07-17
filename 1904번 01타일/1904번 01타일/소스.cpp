#include <iostream>

int arr[1000001];

int main()
{
	int N;
	std::cin >> N;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= N; i++)
	{
		arr[i] = arr[i - 1] % 15746 + arr[i - 2] % 15746;
	}
	std::cout << arr[N] % 15746;
}