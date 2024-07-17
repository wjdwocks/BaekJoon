#include <iostream>
#include <cmath>

int result = 0;	

int func1(int a, int b, int c)
{
	int spare = 0;
	if (a <= 0 || b <= 0 || c <= 0)
	{
		spare += 1;
	}
	else if (a > 20 || b > 20 || c > 20)
	{
		spare += func1(20, 20, 20);
	}
	else if (a == b && b == c)
	{
		spare += pow(2, a);
	}
	else if (a < b && b < c)
	{
		spare += func1(a, b, c - 1) + func1(a, b - 1, c - 1) - func1(a, b - 1, c);
	}
	else
		spare += func1(a - 1, b, c) + func1(a - 1, b - 1, c) + func1(a - 1, b, c - 1) - func1(a - 1, b - 1, c - 1);

	return spare;
}

int main()
{
	int a, b, c;
	
	while (1)
	{
		result = 0;	
		std::cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;

		result = func1(a, b, c);

		printf("w(%d, %d, %d) = %d\n", a, b, c, result);
	}

}