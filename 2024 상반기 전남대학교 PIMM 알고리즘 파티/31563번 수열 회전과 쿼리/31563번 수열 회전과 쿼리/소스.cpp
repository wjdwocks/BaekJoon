#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, Q;

	std::cin >> N >> Q;

	std::vector<long long> vec(N + 1, 0);

	int temp = 0;
	for (int i = 1; i < N + 1; ++i)
	{
		std::cin >> temp;
		vec[i] = vec[i - 1] + temp; // 누적 합 배열의 형태로 만든다.
	}

	int start = 0;

	int first, second, third;
	long long result = 0;

	for (int i = 0; i < Q; ++i)
	{
		first = second = third = 0;
		std::cin >> first;
		if (first == 3)
		{
			std::cin >> second >> third;
			second = second + start > N ? second + start - N : second + start;
			third = third + start > N ? third + start - N : third + start;

			if (second < third)
				result = vec[third] - vec[second - 1];
			else if (second > third)
				result = vec[third] + vec[N] - vec[second - 1];

			std::cout << result << '\n';
			result = 0;
		}
		else
		{
			std::cin >> second;
			if (first == 2)
			{
				start = start + second;
				start = start > N ? start - N : start;
			}

			else if (first == 1)
			{
				start = start - second;
				start = (start <= 0) ? N + start : start;
			}
		}
	}
	
}