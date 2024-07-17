#include <iostream>

int main()
{
	int N;
	std::cin >> N;

	/*
	arr[1] = 1 // 1
	arr[2] = 1 // 10
	arr[3] = 2 // 101 , 100
	arr[4] = 3 // 1000 1010 1001
	arr[5] = 5 // 10000 10101 10010 10001 10100
	arr[6] = 8 // 100000 / 101000 100100 100010 100001 / 101010 101001 100101
	-> 1 + arr[4] + arr[3] + arr[2] + arr[1] = 1 + 3 + 2 + 1 + 1
	arr[5] = 1 + arr[3] + arr[2] + arr[1] --> arr[4] + arr[5] = arr[6]
	*/
	long long* dp = new long long[N + 1];
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	std::cout << dp[N];
}