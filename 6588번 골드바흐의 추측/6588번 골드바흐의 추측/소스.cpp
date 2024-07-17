#include <iostream>
#include <cmath>

bool sosu(int temp)
{
	int last = sqrt(temp);
	if (temp == 1)
		return false;
	for (int i = 2; i <= last; i++)
	{
		if (temp % i == 0)
			return false;
	}
	return true;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int temp;
	while (1)
	{
		std::cin >> temp;
		if (temp == 0)
			break;
		for (int i = 3; i < temp; i += 2)
		{
			if (sosu(i) == true && sosu(temp-i) == true)
			{
				std::cout << temp << " = " << i << " + " << temp - i << '\n';
				break;
			}
		}
	}
}