#include <iostream>

int main()
{
	int a1, a0, c, n0;
	std::cin >> a1>> a0;
	std::cin >> c;
	std::cin >> n0;
	int temp = 10000000, i = n0;

	while (temp > ((c * i) - (a1 * i + a0)))
	{
		if (a1 * i + a0 > c * i)
		{
			std::cout << 0;
			return 0;
		}
		temp = c * i - (a1 * i + a0);
		i++;
	}
	std::cout << 1;
}