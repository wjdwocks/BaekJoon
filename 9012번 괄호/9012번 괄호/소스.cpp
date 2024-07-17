#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

int main()
{
	int T;
	std::cin >> T;
	getchar();
	std::vector<int> v;
	
	char str[53];
	while(T--)
	{
		bool result = true;
		fgets(str, sizeof(str), stdin);
		for (int i = 0; i < strlen(str)-1; i++)
		{
			if (str[i] == '(')
				v.emplace_back(1);
			else if (str[i] == ')')
			{
				if (v.size() > 0)
					v.pop_back();
				else
					result = false;
			}
		}

		if (result == false || v.size() != 0)
			std::cout << "NO" << '\n';
		else
			std::cout << "YES" << '\n';
		v.clear();
	}
}