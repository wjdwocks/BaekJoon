#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> v;
	int N;
	std::cin >> N;

	int* arr = new int[N];

	for (int i = 0; i < N; i++)
		std::cin >> arr[i];

	int min = 0, prev = arr[0];
	int count;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > prev)
			continue;
		count = 1;
		prev = min = arr[i];

		for (int j = i; j < N; j++)
		{
			if (arr[j] > min)
			{
				count++;
				min = arr[j];
			}
		}
		v.emplace_back(count);
	}

	std::sort(v.rbegin(), v.rend());
	for (auto i : v)
		std::cout << i << '\n';
}