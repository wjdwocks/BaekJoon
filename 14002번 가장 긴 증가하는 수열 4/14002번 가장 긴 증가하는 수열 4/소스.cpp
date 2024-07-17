#include <iostream>
#include <vector>
#include <algorithm>

typedef struct node
{
	std::vector<int> v;
	int res;
};

bool compare(const node& a, const node& b)
{
	return a.res < b.res;
}



int main()
{
	int N;
	std::cin >> N;
	int* arr = new int[N] {0};
	node* dp = new node[N];
	for (int i = 0; i < N; i++)
	{
		std::cin >> arr[i];
	}
	for (int j = 0; j < N; j++)
	{
		dp[j].res = 1;
		for (int i = 0; i < j; i++)
		{
			if (arr[i] < arr[j])
			{
				if (dp[j].res < dp[i].res + 1)
				{
					dp[j].res = dp[i].res + 1;
					dp[j].v = dp[i].v;
				}
			}
		}
		dp[j].v.emplace_back(arr[j]);
	}
	
	std::sort(dp, dp + N, compare);

	std::cout << dp[N - 1].res << '\n';
	for (auto i : dp[N - 1].v)
		std::cout << i << ' ';

}