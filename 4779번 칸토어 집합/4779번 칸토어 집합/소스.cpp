#include <iostream>
#include <vector>
#include <cmath>

void func(std::vector<std::string>& vec, int first, int last)
{
	int range = last - first + 1;
	if (range == 1)
		return;
	int temp = range / 3;
	for (int i = first + temp; i < first + temp + temp; i++)
	{
		vec[i] = " ";
	}
}


int main()
{
	int N;
	
	while (std::cin >> N)
	{
		std::vector<std::string> vec(std::pow(3, N) + 1, "-");
		vec[pow(3, N)] = " ";
		while (N--)
		{
			int first = 0;
			for (int i = 1; i < vec.size(); ++i)
			{
				if (vec[i] == " " && vec[i - 1] == "-")
					func(vec, first, i-1);
				else if (vec[i] == "-" && vec[i - 1] == " ")
					first = i;
			}
		}
		for (auto& i : vec)
			std::cout << i;
		putchar('\n');
	}

}