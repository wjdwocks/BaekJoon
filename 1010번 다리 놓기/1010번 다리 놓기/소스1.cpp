#include <iostream>

// 5를 빼보고 있으면 그거 + 1
// 5를 뺐는데 -1이면 2를 빼보고 있으면 그거 + 1;

int main()
{
	int n;
	std::cin >> n;
	int* arr = new int[100001];
	arr[1] = -1;
	arr[2] = 1;
	arr[3] = -1;
	arr[4] = 2;
	arr[5] = 1;
	for (int i = 6; i <= 100000; i++)
	{
		if (arr[i - 5] != -1)
			arr[i] = arr[i - 5] + 1;
		else if (arr[i - 2] != -1)
			arr[i] = arr[i - 2] + 1;
	}

	std::cout << arr[n];
}