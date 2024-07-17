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
			if (A % i == 0) // 나누어 떨어진다면 ? 
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
	// 두개를 소인수분해해서 같은 소수인 거를 체크해서 곱하는 거에 뺌.

	func(A, v1); // A를 소인수분해하여 v1에 넣음.
	func(B, v2); // B를 소인수분해 v2.

	for (int i : v1)
	{
		if(m1.find(i) == m1.end()) // 키값이 없다면 
			m1.emplace(i, 1);
		else
			m1[i]++;
	}
	
	for (int i : v2)
	{
		if (m2.find(i) == m2.end()) // 키값이 없다면 
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