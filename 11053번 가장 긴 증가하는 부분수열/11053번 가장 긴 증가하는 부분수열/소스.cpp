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
	// bottom-up����� dp����ó�� ����
	
	for (int j = 0; j < N; j++)
	{
		dp[j] = 1; 
		for (int i = 0; i < j; i++) // dp[i]�� �����ϱ� ���� �տ������� �ϳ��� �˻��ϸ� arr[i]���� �۴ٸ� �װ� + 1 = dp[i]�� �ϴ� ������ �� ���� �ִ��� dp[i]�� �Ҵ���.
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