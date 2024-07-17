#include <iostream>
#include <vector>
#include <algorithm>

// 앞에서 부터 확인해 가면서 dp[i] = max(dp[i-1]+arr[i], arr[i])

int main()
{
	int N;
	std::cin >> N;
	std::vector<int> arr(N, 0);
	std::vector<int> dp(N, 0);

	for (int i = 0; i < N; i++)
		std::cin >> arr[i];

	dp[0] = arr[0];

	for (int i = 1; i < N; i++)
	{
		dp[i] = std::max(dp[i - 1] + arr[i], arr[i]);
	}
	std::sort(dp.begin(), dp.end());
	std::cout << dp[N - 1];
}