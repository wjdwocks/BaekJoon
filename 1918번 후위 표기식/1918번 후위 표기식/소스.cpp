#include <iostream>
#include <stack>
#include <vector>

int main()
{
	std::vector<int> v;
	std::stack<char> s;
	std::string str;
	std::cin >> str;

	char l = NULL, r = NULL;

	int cursor = 0;
	while (str[cursor] != NULL)
	{
		if (str[cursor] == '(')
		{
			l = '(';
			s.push(str[cursor]);
			cursor++;
			continue;
		}
		if (str[cursor] == ')')
		{
			while (s.top() != '(')
			{
				std::cout << s.top();
				s.pop();
			}
			s.pop();
		}
		if (str[cursor] == '*' || str[cursor] == '/')
		{
			while (!s.empty())
			{
				char temp = s.top();
				if (temp == '*' || temp == '/')
				{
					std::cout << temp;
					s.pop();
				}
				else
					break;
			}
			s.push(str[cursor]);
		}
		else if (str[cursor] == '+' || str[cursor] == '-')
		{
			while (!s.empty())
			{
				char temp = s.top();
				if (temp == '*' || temp == '/')
				{
					std::cout << temp;
					s.pop();
				}
				else if (temp == '+' || temp == '-')// +, -
				{
					std::cout << temp;
					s.pop();
				}
				else
					break;
			}
			s.push(str[cursor]);
		}
		if (65 <= str[cursor] && str[cursor] <= 90)
		{
			std::cout << str[cursor];
		}
		cursor++;
	}

	while (!s.empty())
	{
		std::cout << s.top();
		s.pop();
	}
}