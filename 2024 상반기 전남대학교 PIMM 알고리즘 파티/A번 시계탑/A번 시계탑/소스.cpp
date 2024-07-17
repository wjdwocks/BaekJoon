#include <iostream>

int main()
{
	int M;
	std::cin >> M;


	if (M <= 30 && M % 2 == 0)
	{
		std::cout << M / 2 << "." << 0;
	}
	else if (M <= 30 && M % 2 == 1)
	{
		std::cout << M / 2 << "." << 5;
	}
	else if (M > 30)
	{
		double result = (M - 30) * 1.5;
		printf("%.1f", result + 15);
	}
		

}