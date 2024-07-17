#include <iostream>
#include <cmath>



int func(int n, int m)
{
	int result = 0;
	for (int i = n+1; i <= m; i++) // ÃÖ´ë 10¸¸
	{
		if (i == 2 || i == 3)
		{
			result++;
			continue;
		}
		int temp = sqrt(i);
		for (int j = 2; j <= temp; j++)
		{
			if (i % j == 0)
			{
				break;
			}
			if (j == temp)
				result++;
		}
	}
	return result;
}

int main()
{
	int num = 0;
	std::cin >> num;
	while (num != 0)
	{
		std::cout << func(num, 2 * num) << std::endl;
		std::cin >> num;
	}
}