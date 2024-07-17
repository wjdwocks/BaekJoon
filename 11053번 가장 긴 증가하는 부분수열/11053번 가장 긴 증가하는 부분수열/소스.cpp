#include <iostream>
#include <vector>
#include <algorithm>

// 

int main()
{
	std::vector<int> v;
	int N;
	std::cin >> N;
	int* arr = new int[N] {0};
	int* dp = new int[N] {0};
	for (int i = 0; i < N; i++)
		std::cin >> arr[i];
	// bottom-up방식의 dp문제처럼 접근
	
	for (int j = 0; j < N; j++)
	{
		dp[j] = 1; 
		for (int i = 0; i < j; i++) // dp[i]를 결정하기 위해 앞에서부터 하나씩 검사하며 arr[i]보다 작다면 그것 + 1 = dp[i]를 하는 식으로 그 중의 최댓값을 dp[i]에 할당함.
		{
			if (arr[i] < arr[j])
			{
				dp[j] = std::max(dp[i] + 1, dp[j]);
			}
		}
	}
	std::sort(&dp[0], &dp[N]);
	std::cout << dp[N - 1];
}