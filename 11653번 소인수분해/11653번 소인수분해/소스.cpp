#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
// M이상 N이하 자연수 중 소수들의 합, 최솟값.

bool func(int target)
{
	for (int i = 2; i <= sqrt(target); i++)
	{
		if (target % i == 0)
			return false;
	}
	return true;
}

int main()
{
	std::vector<int> v;
	int N;
	std::cin >> N;
	if (N == 1)
	{
		return 0;
	}
	while (N > 1)
	{
		for (int i = 2; i <= N; i++)
		{
			if (N % i == 0)
			{
				N /= i;
				v.emplace_back(i);
				break;
			}
		}
	}

	std::sort(v.begin(), v.end());
	for (auto i : v)
		std::cout << i << '\n';

}