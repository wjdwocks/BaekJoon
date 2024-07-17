#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


int main()
{
	std::ios_base::sync_with_stdio(false);

	std::vector<std::string> v;
	std::map<std::string, int> m;

	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::string str1, str2;
		std::cin >> str1 >> str2;
		if (str2 == "enter")
		{
			if (m[str1] == 0)
				m[str1] = 1;
			m.emplace(str1, 1);
		}
		else if (str2 == "leave")
			m[str1] = 0;
	}

	for (auto i : m)
	{
		if (i.second)
			v.emplace_back(i.first);
	}
	
	std::sort(v.rbegin(), v.rend());
	
	for (auto i : v)
		std::cout << i << '\n';
}