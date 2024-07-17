#include <iostream>

int main()
{
	std::string str;
	std::cin >> str;
	int arr[26]{ 0 };
	for (int i = 0; i < str.length(); i++)
	{
		arr[str[i] - 97]++;
	}
	for (int i = 0; i < 26; i++)
		std::cout << arr[i] << ' ';
}