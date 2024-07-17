#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

void func(std::vector<int>& v1, int son)
{
	int limit = sqrt(son), temp = son, total = 1;
	while (1)
	{
		for (int i = 2; i <= limit; i++)
		{
			if (son % i == 0) // 나누어 떨어지면
			{
				v1.emplace_back(i);
				son /= i;
				total *= i;
				break;
			}
			if (i == limit)
			{
				v1.emplace_back(temp / total);
				return;
			}
		}
	}
}


int main()
{
	std::vector<int> v1, v2, v3; // 분자의 소인수, 분모의 소인수, 소인수분해 저장
	int A, B, C, D; // A/B, C/D
	std::cin >> A >> B;
	std::cin >> C >> D;

	int son = A * D + B * C;
	int mom = B * D; // 분자와 분모의 공약수를 구해서 둘다 나눈다.

	//func(v1, son); // 30000
	//func(v2, mom); // 30000

	//for (auto i : v1)
	//{
	//	for (auto j : v2)
	//	{
	//		if (i == j)
	//		{
	//			v3.emplace_back(i);
	//			break;
	//		}
	//	}
	//}

	//std::sort(v3.rbegin(), v3.rend());

	//for (auto i : v3)
	//{
	//	if(son % i == 0 && mom % i == 0)
	//		son /= i, mom /= i;
	//}
	int gcd;
	while ((gcd = GCD(son, mom)) != 1) // 1이면 공약수가 없다.
	{
		son /= gcd;
		mom /= gcd;
	}


	std::cout << son << ' ' << mom;
}