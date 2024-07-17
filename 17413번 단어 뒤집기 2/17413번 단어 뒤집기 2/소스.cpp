#include <iostream>
#include <algorithm>
#include <cstring>

void reverse(char* str, int l, int r)
{
	int mid = (l + r) / 2;
	for (int i = l; i <= mid; i++)
	{
		std::swap(str[l], str[r]);
		l++;
		r--;
	}
}

int main()
{
	char str[100002];
	fgets(str, sizeof(str), stdin);
	int l =0 , r = 0;
	char L = NULL, R = NULL;
	
	int length = strlen(str);
	for (int i = 0; i < length; i++)
	{
		if (L == '<')
		{
			if (str[i] != '>')
			{
				continue;
			}
			else
			{
				l = i + 1;
				L = NULL;
				continue;
			}
		}
		if (str[i] == '<')
		{
			L = '<';
			r = i - 1;
			if (l < r)
				reverse(str, l, r);
		}
		if (str[i] == ' ')
		{
			r = i - 1;
			if(l < r)
				reverse(str, l, r);
			l = i + 1;
		}
		if (str[i] == '\n')
		{
			r = i - 1;
			if (l < r)
				reverse(str, l, r);
		}

	}

	for (int i = 0; i < length; i++)
	{
		std::cout << str[i];
	}
}