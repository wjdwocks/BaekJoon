#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	
	if (N % 2 == 1)
		std::cout << "SK";
	else
		std::cout << "CY";
}