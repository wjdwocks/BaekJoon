#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

long long func(long long num)
{
	long long temp = sqrt(num);
	while (1) // next(n)
	{
		for (long long i = 2; i <= temp; i++) // root(n)
		{
			if (num % i == 0)
				break;
			if (i == temp)
			{
				return num;
			}
		}
		num += 2;
	}
}

int main()
{
	long long n;
	std::cin >> n;
	long long num;
	while (n--)
	{
		scanf("%lld", &num);

		if (num <= 2)
		{
			std::cout << 2 << std::endl;
			continue;
		}
		if (num == 3)
		{
			std::cout << 3 << std::endl;
			continue;
		}
		if (num % 2 == 0)
			num++;
		std::cout << func(num) << std::endl;
	}

}