#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

int main()
{
	std::vector<char> v;
	int N;
	std::cin >> N;
	getchar();
	while (N--)
	{
		char str[1000];
		fgets(str, sizeof str, stdin);

		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] != ' ' && str[i] != '\n')
			{
				v.emplace_back(str[i]);
			}
			else if (str[i] == '\n' || str[i] == ' ')
			{
				std::reverse(v.begin(), v.end());
				for (auto i : v)
					std::cout << i;
				putchar(str[i]);
				v.clear();
			}
		}

	}
}