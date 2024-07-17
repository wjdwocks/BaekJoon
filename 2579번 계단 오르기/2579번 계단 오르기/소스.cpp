#include <iostream>
#include <algorithm>

int main()
{
	int T;
	std::cin >> T;
	int* arr = new int[T + 1];
	int* dp = new int[T + 1];
	for(int i=1;i<=T;i++)
	{
		std::cin >> arr[i];
	}

	dp[1] = arr[1]; // 1번째 계단은 그 자신.
	dp[2] = arr[1] + arr[2];
	dp[3] = std::max(arr[1] + arr[3], arr[2] + arr[3]);
	for (int i = 4; i <= T; i++)
	{
		dp[i] = std::max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}
	std::cout << dp[T];
}