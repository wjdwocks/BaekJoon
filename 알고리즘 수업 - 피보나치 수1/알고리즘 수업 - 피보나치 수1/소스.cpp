#include <iostream>

int main()
{
	int t;
	std::cin >> t;
	int arr[40] = { 0 , };
	arr[1] = 1;
	arr[2] = 1;
	for (int i = 3; i <= t; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	std::cout << arr[t] << ' ' << t - 2;
}