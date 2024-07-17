#include <iostream>
#include <algorithm>

std::pair <long long, long long> func(long long num)
{
	long long two = 0;
	long long five = 0;

	for (long long i = 2; i <= num; i *= 2)
	{
		two += num / i;
	}
	for (long long i = 5; i <= num; i *= 5)
	{
		five += num / i;
	}

	return std::make_pair(two, five);
}

int main()
{
	int n, m;
	std::cin >> n >> m; // nCm
	// nCm == n! / ((n-m)! * m!)
	// n!에서 2와 5의 갯수 - (n-m)!에서 2와 5의 개수 - m!에서 2와 5의 개수 중 작은거.
	std::pair<long long, long long> fac_N = func(n);
	std::pair<long long, long long> fac_NM = func(n - m);
	std::pair<long long, long long> fac_M = func(m);

	long long two = fac_N.first - fac_NM.first - fac_M.first;
	long long five = fac_N.second - fac_NM.second - fac_M.second;

	std::cout << std::min(two, five);

}