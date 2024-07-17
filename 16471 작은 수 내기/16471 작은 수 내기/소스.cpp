#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;
	std::vector<int> v1(N), v2(N), v3(N);
	int temp;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> temp;
		v1[i] = temp;
	}
	for (int i = 0; i < N; ++i)
	{
		std::cin >> temp;
		v2[i] = temp;
	}
	std::sort(v2.begin(), v2.end(), [](int a1, int a2) {return a1 < a2; });
	std::sort(v1.begin(), v1.end(), [](int a1, int a2) {return a1 < a2; });
	int last = N - 1, start = 0;
	for (int i = 0; i < N; ++i)
	{
		if (v2[i] > v1[start])
			v3[i] = v1[start++];
		else
			v3[i] = v1[last--];
	}
	int score = 0;
	for (int i = 0; i < N; ++i)
	{
		if (v3[i] < v2[i])
			score++;
	}
	if (score >= (N + 1) / 2)
		std::cout << "YES";
	else
		std::cout << "NO";
}