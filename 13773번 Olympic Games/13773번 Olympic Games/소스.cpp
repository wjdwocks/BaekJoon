#include <iostream>

int main()
{
	int Year;
	while ((std::cin >> Year) && Year != 0)
	{
		if ((Year - 1896) % 4 == 0)
		{
			if ((1914 <= Year && Year <= 1918) || (1939 <= Year && Year <= 1945))
				std::cout << Year << " Games cancelled" << std::endl;
			else if (Year > 2020)
				std::cout << Year << " No city yet chosen" << std::endl;
			else if(Year < 1896)
				std::cout << Year << " No summer games" << std::endl;
			else
				std::cout << Year << " Summer Olympics" << std::endl;
		}
		else
		{
			std::cout << Year << " No summer games" << std::endl;
		}
	}
}