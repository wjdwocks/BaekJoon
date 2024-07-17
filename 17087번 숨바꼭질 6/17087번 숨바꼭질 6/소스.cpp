#include <iostream>
#include <vector>
#include <algorithm>

int GCD(int a, int b)
{
	int max = std::max(a, b);
	int min = std::min(a, b);
	if (min == 0)
		return max;
	return GCD(max - min, min);
}

int main()
{
	std::vector<int> pq, bet;
	int N, S; // ������ ��ġ
	std::cin >> N >> S;
	pq.emplace_back(S);
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		std::cin >> arr[i]; // ������ ��ġ
		pq.emplace_back(arr[i]);
	}
	if (N == 1)
	{
		if (S > arr[0])
			std::cout << S - arr[0];
		else
			std::cout << arr[0] - S;
		return 0;
	}

	std::sort(pq.begin(), pq.end());
	// ������ ��ġ�� ũ�� ������� ������ �� ���ݵ��� �ִ� ������� ���Ѵ�.

	for (int i = 0; i < pq.size() - 1; i++)
	{
		bet.emplace_back(pq[i + 1] - pq[i]);
	}

	std::sort(bet.rbegin(), bet.rend());
	
	int dmddo = GCD(bet[0], bet[1]);

	for (int i = 2; i < bet.size(); i++)
	{
		dmddo = GCD(dmddo, bet[i]);
	}
	std::cout << dmddo;
}