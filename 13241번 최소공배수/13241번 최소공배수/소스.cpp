#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

void func(int A, std::vector<int>& v1)
{
	int temp = A;
	int limit = sqrt(A);
	int result = 1;
	while (A > 1)
	{
		if (limit == 1)
		{
			v1.emplace_back(temp / result);
				return;
		}
		for (int i = 2; i <= limit; i++)
		{
			if (A % i == 0) // ������ �������ٸ� ? 
			{
				v1.emplace_back(i);
				result *= i;
				A /= i;
				break;
			}
			if (i == limit)
			{
				v1.emplace_back(temp / result);
				return;
			}

		}
	}

}

int main()
{
	std::map<int, int> m1, m2, m3;
	std::vector<int> v1, v2, v3;
	int A, B;
	std::cin >> A >> B;
	// �ΰ��� ���μ������ؼ� ���� �Ҽ��� �Ÿ� üũ�ؼ� ���ϴ� �ſ� ��.

	func(A, v1); // A�� ���μ������Ͽ� v1�� ����.
	func(B, v2); // B�� ���μ����� v2.

	for (int i : v1)
	{
		if(m1.find(i) == m1.end()) // Ű���� ���ٸ� 
			m1.emplace(i, 1);
		else
			m1[i]++;
	}
	
	for (int i : v2)
	{
		if (m2.find(i) == m2.end()) // Ű���� ���ٸ� 
			m2.emplace(i, 1);
		else
			m2[i]++;
	}


	long long result = 1;
	int prev = 0;
	for (int i : v1)
	{
		if (prev != i)
		{
			if (m2[i] > m1[i])
				m3.emplace(i, m2[i]);
			else
				m3.emplace(i, m1[i]);
		}
		prev = i;
	}
	prev = 0;
	for (int i : v2)
	{
		if (prev != i)
		{
			if (m2[i] > m1[i])
				m3.emplace(i, m2[i]);
			else
				m3.emplace(i, m1[i]);
		}
		prev = i;
	}

	for (auto i : m3)
	{
		result *= std::pow(i.first, i.second);
	}
	std::cout << result;
}