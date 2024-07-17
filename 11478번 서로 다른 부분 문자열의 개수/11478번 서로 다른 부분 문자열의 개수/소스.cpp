#include <iostream>
#include <string>
#include <set>

int main()
{
	std::set<std::string> myset;
	int result = 0;
	std::string str;
	std::cin >> str;

	int length = str.length() - 1;
	std::string temp;
	
	int j = 1;
	while (j <= length) // 1000
	{
		for (int i = 0; i <= length; i++) // 1000
		{
			if (i + j > length+1)
				break;
			std::string substr = str.substr(i, j); // 1000
			myset.emplace(substr);
		}
		j++;
	}

	std::cout << myset.size() + 1;
	
}