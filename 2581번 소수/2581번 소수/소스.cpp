#include <iostream>
#include <vector>
#include <cmath>
// M이상 N이하 자연수 중 소수들의 합, 최솟값.

bool func(int target)
{
	for (int i = 2; i <= target/2; i++)
	{
		if (target % i == 0)
			return false;
	}
	return true;
}

int main()
{
	std::vector<int> v;
	int M, N, total = 0;
	std::cin >> M;
	std::cin >> N;
	for (int i = M; i <= N; i++)
	{
		if (i == 1)
			continue;
		if (func(i))
		{
			v.emplace_back(i);
			total += i;
		}
	}
	if (v.empty())
		std::cout << -1;
	else
	{
		std::cout << total << std::endl;
		std::cout << v[0];
	}
	
}