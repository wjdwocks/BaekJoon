#include <iostream>
#include <sstream>

int plus = 0;
int minus = 0;
bool first_minus = false;

std::string func(std::string str, int start, int last)
{
	return str.substr(start, last - start + 1);
}

int main()
{
	std::string str = "";
	std::cin >> str;
	std::stringstream ss;
	int length = str.length();

	std::string substring;

	for (int i = 0, first = 0, temp = 0; i <= length; ++i)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == NULL) // 부호가 나온다면
		{
			substring = func(str, first, i-1);
			first = i + 1;
			ss.clear();
			ss << substring;
			ss >> temp;

			if (first_minus)
				minus += temp;
			else
				plus += temp;

			if (first_minus == false && str[i] == '-')
				first_minus = true;
		}
	}
	std::cout << plus - minus;
}