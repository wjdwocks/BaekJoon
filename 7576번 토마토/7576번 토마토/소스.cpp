#include <iostream>
#include <deque>
#include <tuple>

int tomato[1002][1002];
int day = 0;
int total_tomato = 0;
int good_tomato = 0;

void bfs(std::deque<std::tuple<int, int>>& d)
{
	if (total_tomato == good_tomato)
		return;
	if (d.empty())
		return;
	int num = d.size();
	while (num--)
	{
		int m, n;
		std::tie(m, n) = d.front();
		d.pop_front();
		if (tomato[m - 1][n] == -1)
		{
			tomato[m - 1][n] = 1;
			good_tomato++;
			d.emplace_back(m - 1, n);
		}
		if (tomato[m + 1][n] == -1)
		{
			tomato[m + 1][n] = 1;
			good_tomato++;
			d.emplace_back(m + 1, n);
		}
		if (tomato[m][n - 1] == -1)
		{
			tomato[m][n - 1] = 1;
			good_tomato++;
			d.emplace_back(m, n - 1);
		}
		if (tomato[m][n + 1] == -1)
		{
			tomato[m][n + 1] = 1;
			good_tomato++;
			d.emplace_back(m, n + 1);
		}
	}
	day++;
	bfs(d);
}

int main()
{
	int M, N;
	std::cin >> M >> N;
	int temp;
	std::deque<std::tuple<int, int>> d;
	for (int n = 1; n <= N; ++n)
	{
		for (int m = 1; m <= M; ++m)
		{
			std::cin >> temp;
			if (temp == 0) // 전역변수라 0으로 초기화되어서 -1을 안익은 토마토로.
			{
				tomato[m][n] = -1;
				total_tomato++;
			}
			else if (temp == 1) // 익은 토마토.
			{
				tomato[m][n] = 1;
				total_tomato++;
				good_tomato++;
				d.emplace_back(m, n);
			}
		}
	}
	bfs(d);
	if (good_tomato == total_tomato)
		std::cout << day;
	else
		std::cout << -1;
}