#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;
	int N;
	std::cin >> N;
	if (N == 0)
	{
		std::cout << 0;
		return 0;
	}
	while (N != 0)
	{
		if (N % 2 == 1 || N % 2 == -1) // 음수이고 홀수라면
		{
			v.emplace_back(1);
			N = N - 1;
			N /= -2;
		}
		else if (N % 2 == 0) // 짝수라면
		{
			v.emplace_back(0);
			N /= -2;
		}
	}
	for (int i = v.size() - 1; i >= 0; i--)
	{
		std::cout << v[i];
	}
}
