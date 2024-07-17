#include <iostream>

int main()
{
	int K;
	std::cin >> K;

	int* arr1 = new int[46];
	int* arr2 = new int[46];
	arr1[0] = 1;
	arr2[0] = 0;

	arr1[1] = 0;
	arr2[1] = 1;
	
	arr1[2] = 1;
	arr2[2] = 1;

	for (int i = 2; i < 46; i++)
	{
		arr1[i] = arr2[i - 1];
		arr2[i] = arr1[i - 1] + arr2[i - 1];
	}
	std::cout << arr1[K] << ' ' << arr2[K];
}