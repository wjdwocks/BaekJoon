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
			if (son % i == 0) // ������ ��������
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
	std::vector<int> v1, v2, v3; // ������ ���μ�, �и��� ���μ�, ���μ����� ����
	int A, B, C, D; // A/B, C/D
	std::cin >> A >> B;
	std::cin >> C >> D;

	int son = A * D + B * C;
	int mom = B * D; // ���ڿ� �и��� ������� ���ؼ� �Ѵ� ������.

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
	while ((gcd = GCD(son, mom)) != 1) // 1�̸� ������� ����.
	{
		son /= gcd;
		mom /= gcd;
	}


	std::cout << son << ' ' << mom;
}