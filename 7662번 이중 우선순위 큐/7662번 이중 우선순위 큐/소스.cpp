#include <iostream>
#include <set>
#include <string>

int main()
{
	int T;
	std::cin >> T;
	std::string temp;
	std::string sub_temp;
	int num;
	while (T--)
	{
		int k;
		std::cin >> k;
		getchar();
		std::multiset<int> ms;
		while (k--)
		{
			std::getline(std::cin, temp);
			sub_temp = temp.substr(2);
			num = std::stoi(sub_temp);
			if (temp[0] == 'I')
				ms.emplace(num);
			else if (temp[0] == 'D' && num == -1 && !ms.empty())
				ms.erase(ms.begin());
			else if (temp[0] == 'D' && num == 1 && !ms.empty())
				ms.erase(--ms.end());
		}
		if (ms.empty())
			std::cout << "EMPTY" << '\n';
		else
			std::cout << *(--ms.end()) << ' ' << *(ms.begin()) << '\n';
	}

}