#include <iostream>
#include <sstream>

std::string str[3];
std::string result = "";

std::string func(std::string str)
{
	if (str[0] != 'F' && str[0] != 'B')
		return str;	// 숫자일 때
	else 
		return "no";

}

int main()
{
	std::stringstream ss;
	int sint = 0;
	std::cin >> str[0] >> str[1] >> str[2];

	for (int i = 0; i < 3; ++i)
	{
		std::string temp = func(str[i]);
		if (temp.compare("no") == 0)
		{
			sint++;
			continue;
		}
		else
		{
			ss << temp;
			ss >> sint;
			ss.clear();
			continue;
		}
	}
	sint++;
	if (sint % 5 == 0 && sint % 3 == 0)
		result = "FizzBuzz";
	else if (sint % 5 == 0 && sint % 3 != 0)
		result = "Buzz";
	else if (sint % 5 != 0 && sint % 3 == 0)
		result = "Fizz";
	else
		result = std::to_string(sint);
	std::cout << result;
}