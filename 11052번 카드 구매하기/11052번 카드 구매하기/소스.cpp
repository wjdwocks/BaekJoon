#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;

	int* card = new int[N];
	for (int i = 0; i < N; ++i)
		std::cin >> card[i];

	int* dp = new int[N];
	//dp[i] = max(card[i], dp[i - 1] + card[1], dp[i - 2] + card[2], dp[i - 3] + card[3]...);
	for (int i = 0; i < N; ++i)
	{
		int max = card[i];
		for (int j = i - 1; j >= 0; --j)
		{
			if (max < card[i - j-1] + dp[j])
				max = card[i - j-1] + dp[j];
		}
		dp[i] = max;
	}
	std::cout << dp[N - 1];
}