#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int T_shirt = 0;
	int N, T, P;
	std::vector<int> v(6);
	std::cin >> N;
	std::cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4] >> v[5];
	std::cin >> T >> P;
	int max = 0;
	std::for_each(v.begin(), v.end(), [T, &T_shirt](int num) {if (num % T != 0) T_shirt += num / T + 1; else T_shirt += num / T; });

	std::cout << T_shirt << std::endl;
	std::cout << N / P << ' ' << N % P;
}