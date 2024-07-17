#include <iostream>
#include <deque>
#include <algorithm>

bool reverse = false;
std::deque<int> func(std::string p, std::deque<int>& v)
{
	reverse = false;
	for (char c : p)
	{
		if (c == 'R')
			reverse = !reverse;
		else if (c == 'D')
		{
			if (v.empty())
			{
				v.emplace_back(-1);
				return v;
			}
			if (reverse)
				v.pop_back();
			else
				v.erase(v.begin());
		}
	}
	return v;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T;
	std::cin >> T;
	std::string trash;
	while (T--)
	{
		std::string p;
		std::cin >> p;
		int n;
		std::cin >> n;
		std::deque<int> v(n);

		if (n == 0)
		{
			bool er = false;
			std::cin >> trash;
			for (char ch : p)
			{
				if (ch == 'D' && !er)
				{
					std::cout << "error" << '\n';
					er = true;
				}
			}
			if (!er)
				std::cout << "[]" << '\n';
			continue;
		}


		char ch;
		std::deque<int>::iterator itr = v.begin();
		while (std::cin >> ch && ch != ']')
			std::cin >> *itr++;
		v = func(p, v);
		if (reverse)
			std::reverse(v.begin(), v.end());

		if (v.empty())
			std::cout << "[]" << '\n';
		else if (v[0] == -1)
			std::cout << "error" << '\n';
		else
		{
			std::cout << '[';
			auto itr = v.begin();
			for(; itr != v.end() - 1; ++itr)
			{
				std::cout << *itr << ',';
			}
			std::cout << *itr;
			std::cout << ']' << '\n';
		}
		
	}
}