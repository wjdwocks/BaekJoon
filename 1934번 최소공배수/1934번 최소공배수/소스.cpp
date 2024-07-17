#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void func(int num, std::vector<int>& v)

{
	v.emplace_back(1);
	while (num > 1)
	{
		for (int i = 2; i <= num; i++)
		{
			if (num % i == 0)
			{
				v.emplace_back(i);
				num /= i;
				break;
			}
		}
	}
}


int main()
{
	int T;

	std::cin >> T;

	while (T--)
	{
		std::vector<int> v1, v2, v3;
		int arr1[45001] = { 0, };
		int arr2[45001] = { 0, };
		int arr3[45001] = { 0, };
		int A, B, result = 1;
		std::cin >> A >> B;
		func(A, v1);
		func(B, v2);
		for (auto i : v1)
			arr1[i]++;

		for (auto i : v2)
			arr2[i]++;

		for (int i = 2; i <= 45000;i++)
		{
			if (arr1[i] != 0)
			{
				v3.emplace_back(std::pow(i,std::max(arr1[i], arr2[i])));
				arr1[i] = 0, arr2[i] = 0;
			}

			if (arr2[i] != 0)
			{
				v3.emplace_back(std::pow(i,std::max(arr1[i], arr2[i])));
				arr1[i] = 0, arr2[i] = 0;
			}
		}
		for (auto i : v3)
		{

			result *= i;
		}
		std::cout << result << '\n';
	}
}