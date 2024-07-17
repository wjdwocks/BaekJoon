#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>


int main()
{
	std::vector<std::string> str1;
	std::vector<std::string> str2;
	std::string str;
	int N, M, result=0;
	std::cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		std::cin >> str;
		str1.emplace_back(str);
	}

	for (int i = 0; i < M; i++)
	{
		std::cin >> str;
		str2.emplace_back(str);
	}

	std::sort(str1.begin(), str1.end());

	for (int i = 0; i < M; i++)
	{
		int l = 0, r = N - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (str1[mid].compare(str2[i]) == 0)
			{
				result++;
				break;
			}
			else if (str1[mid].compare(str2[i]) > 0)
				r = mid - 1;
			else if (str1[mid].compare(str2[i]) < 0)
				l = mid + 1;
		}
	}

	std::cout << result;
}