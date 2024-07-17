#include <iostream>
#include <vector>



int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;
	std::vector<int> v;

	int cmd = 0;

	while (N--)
	{
		std::cin >> cmd;
		if (cmd == 1)
		{
			std::cin >> cmd;
			v.emplace(v.begin(), cmd);
		}
		else if (cmd == 2)
		{
			std::cin >> cmd;
			v.emplace_back(cmd);
		}
		else if (cmd == 3)
		{
			if (v.empty())
				std::cout << -1 << std::endl;
			else
			{
				std::cout << v.front() << std::endl;
				v.erase(v.begin());
			}
		}
		else if (cmd == 4)
		{
			if (v.empty())
				std::cout << -1 << std::endl;
			else
			{
				std::cout << v.back() << std::endl;
				v.pop_back();
			}
		}
		else if (cmd == 5)
		{
			std::cout << v.size() << std::endl;
		}
		else if (cmd == 6)
		{
			if (v.empty())
				std::cout << 1 << std::endl;
			else
				std::cout << 0 << std::endl;
		}
		else if (cmd == 7)
		{
			if (v.empty())
				std::cout << -1 << std::endl;
			else
				std::cout << v.front() << std::endl;
		}
		else if (cmd == 8)
		{
			if (v.empty())
				std::cout << -1 << std::endl;
			else
				std::cout << v.back() << std::endl;
		}
	}
}