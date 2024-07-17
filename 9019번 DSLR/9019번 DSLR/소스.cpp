#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

bool Visit[10000];
int Start, End;

std::string bfs()
{
	std::deque<std::pair<int, std::string>> d;
	d.emplace_back(Start, "");
	while (!d.empty())
	{
		int start = d.front().first;
		std::string str = d.front().second;
		d.pop_front();
		if (start == End)
			return str;

		int dstart = (start * 2) % 10000;
		if (!Visit[dstart]) // D
		{
			d.emplace_back(dstart, str + "D");
			Visit[dstart] = true;
		}

		int sstart = (start - 1) % 10000;
		if (sstart < 0)
			sstart += 10000;
		if (!Visit[sstart]) // S
		{
			d.emplace_back(sstart, str + "S");
			Visit[sstart] = true;
		}


		int lstart = (start * 10) % 10000 + start / 1000;
		if (!Visit[lstart])
		{
			d.emplace_back(lstart, str + "L");
			Visit[lstart] = true;
		}


		int rstart = start / 10 + (start % 10) * 1000;
		if (!Visit[rstart])
		{
			d.emplace_back(rstart, str + "R");
			Visit[rstart] = true;
		}
	}
	return "";
}


int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int T;
	std::cin >> T;
	while (T--)
	{
		std::cin >> Start >> End;
		std::fill(std::begin(Visit), std::end(Visit), false);
		// memset(Visit, false, sizeof(Visit));
		std::cout << bfs() << '\n';
	}
}