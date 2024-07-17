#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
	std::vector<int> v1, v2;
	int N, M;
	std::cin >> N >> M; // N개 집합, M개 집합
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		std::cin >> num;
		v1.emplace_back(num);
	}

	for (int i = 0; i < M; i++)
	{
		int num = 0;
		std::cin >> num;
		v2.emplace_back(num);
	}

	std::sort(v1.begin(), v1.end());
	std::sort(v2.begin(), v2.end());

	int result1 = N, result2 = M;
	for (int i = 0; i < N; i++)
	{
		int l = 0, r = v2.size() - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (v2[mid] == v1[i])
			{
				result1--;
				break;
			}
			else if (v2[mid] > v1[i])
				r = mid - 1;
			else
				l = mid + 1;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int l = 0, r = v1.size() - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (v1[mid] == v2[i])
			{
				result1--;
				break;
			}
			else if (v1[mid] > v2[i])
				r = mid - 1;
			else
				l = mid + 1;
		}
	}

	std::cout << result1 + result2;
}