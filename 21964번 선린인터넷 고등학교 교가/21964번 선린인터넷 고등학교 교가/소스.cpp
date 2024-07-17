#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	std::string str;
	std::cin >> str;
	int len = str.length();
	std::string temp = str.substr(len - 5, 5);
	std::cout << temp;
}