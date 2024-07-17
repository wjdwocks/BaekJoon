#include <iostream>
#include <vector>

int main()
{
	int N, K, L;
	std::cin >> N >> K >> L;
	std::vector<int> v;
	int temp1, temp2, temp3, result = 0;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> temp1 >> temp2 >> temp3;
		if (temp1 + temp2 + temp3 >= K && temp1 >= L && temp2 >= L && temp3 >= L)
		{
			result++;
			v.emplace_back(temp1);
			v.emplace_back(temp2);
			v.emplace_back(temp3);
		}
	}
	std::cout << result << std::endl;
	for (auto i : v)
		std::cout << i << ' ';
}