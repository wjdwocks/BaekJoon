#include <iostream>

int main()
{
	int N, K;
	std::cin >> N >> K;
	int total_hole = 0;
	for (int i = 0; i < K; ++i)
	{
		int temp = 0;
		std::cin >> temp;
		total_hole += temp % 2 == 0 ? temp / 2 : temp / 2 + 1;
	}
	if (total_hole >= N)
		std::cout << "YES";
	else
		std::cout << "NO";
}