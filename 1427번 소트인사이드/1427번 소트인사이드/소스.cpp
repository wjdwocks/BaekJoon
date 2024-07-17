#include <iostream>
#include <algorithm>

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	std::string str;
	std::cin >> str;
	std::sort(str.begin(), str.end(), compare);
	std::cout << str;
}