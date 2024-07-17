#include <iostream>
#include <string>
#include <algorithm>

bool isChar(char c)
{
	if (('0' <= c && c <= '9') || ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || c == '-')
		return true;
	return false;
}

int main()
{
	int max = 0;
	std::string max_str = "";
	std::string line = "";
	std::string temp = "";
	while (std::getline(std::cin, line))
	{
		int start = 0, cnt = 0;
		line += '\0';
		for (int i = 0; i < line.length(); ++i)
		{
			if (!isChar(line[i]))
			{
				temp = line.substr(start, cnt);
				if (temp == "E-N-D")
				{
					start = i + 1;
					cnt = 0;
					continue;;
				}
				max_str = cnt > max ? temp : max_str;
				max = cnt > max ? cnt : max;
				start = i + 1;
				cnt = 0;
			}
			else
			{
				cnt++;
			}
		}
		if (temp == "E-N-D")
			break;
	}
	for (char& c : max_str)
		c = std::tolower(c);
	std::cout << max_str;
}