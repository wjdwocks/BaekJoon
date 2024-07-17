#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool func(std::string& str1, std::string& str2)
{
	if (str1[0] == str2[0] && str1[2] == str2[2] && str1[4] == str2[4])
		return true;
	else
		return false;
}

int main()
{
	int N, M, T;
	std::cin >> N >> M;
	int songLength;
	std::string song;
	std::string name;

	std::pair<std::string, std::string> songs[4];

	for (int i = 0; i < N; ++i)
	{
		std::cin >> songLength >> song;
		getchar();
		std::getline(std::cin, name);
		songs[i].first = song;
		songs[i].second = name;
	}

	for (int i = 0; i < M; ++i)
	{
		std::string str;
		std::getline(std::cin, str);
		std::pair<int, std::string> result{ 0, "" };

		for (int i=0;i<N;++i)
		{
			
			if (func(str, songs[i].second))
			{
				result.first++;
				result.second = songs[i].first;
			}
		}
		if (result.first == 0)
			std::cout << "!" << '\n';
		else if (result.first == 1)
			std::cout << result.second << '\n';
		else
			std::cout << "?" << '\n';
	}
}