#include <iostream>
#include <vector>

long long combination(int m, int n) // mCn : m m-1 m-2 m-3 m-4 ...(n개) / n-1 n-2 n-3 ... 1 = m! / n!*m-n!
{
	std::vector<int> v1, v2;
	long long result = 1;
	for (int i = 0; i < n; i++)
	{
		v1.emplace_back(m - i);
		v2.emplace_back(i + 1);
	}
	long long son = 1, parent = 1;
	for (auto i : v1)
		son *= i;
	for (auto i : v2)
		parent *= i;
	result = son / parent;
	return result;
}

int main()
{
	int T;
	std::cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N, M;
		std::cin >> N >> M;
		if (N > (M / 2))
			N = M - N;
		// combination mCn // 0.5초 이내
		std::cout << combination(M, N) << '\n';
	}
}