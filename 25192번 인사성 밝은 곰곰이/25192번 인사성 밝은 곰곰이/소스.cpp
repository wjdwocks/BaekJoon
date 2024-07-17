#include <iostream>
#include <vector>
#include <set>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::set<std::string> s;
	std::vector<std::string> v;
	int N, result = 0;
	std::cin >> N;

	std::string str;
	while (N--)
	{
		std::cin >> str;
		if (str == "ENTER")
		{
			result += s.size();
			s.clear();
			continue;
		}
		s.emplace(str);
	}
	result += s.size();
	std::cout << result;
}