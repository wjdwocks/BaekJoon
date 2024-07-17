#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> v;
	std::string num1, num2;
	std::cin >> num1 >> num2;

	int leng1 = num1.length();
	int leng2 = num2.length();

	int diff = std::max(leng1, leng2) - std::min(leng1, leng2); // 두 수의 길의 차이.

	if (leng1 > leng2) // num1이 더 길면 num2앞에 0을 차이만큼 더함.
	{
		for (int i = 0; i < diff; i++)
		{
			num2 = "0" + num2;
		}
	}
	else if (leng2 > leng1)
	{
		for (int i = 0; i < diff; i++)
			num1 = "0" + num1;
	}

	std::reverse(num1.begin(), num1.end());
	std::reverse(num2.begin(), num2.end());

	for (int i = 0; i < std::max(leng1, leng2); i++)
	{
		v.emplace_back(num1[i] + num2[i] - 96);
	}

	std::reverse(v.begin(), v.end());
	v.emplace(v.begin(), 0);

	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (v[i] > 9)
		{
			v[i] -= 10;
			v[i - 1]++;
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (i == 0 && v[i] == 0)
			continue;
		std::cout << v[i];
	}
}