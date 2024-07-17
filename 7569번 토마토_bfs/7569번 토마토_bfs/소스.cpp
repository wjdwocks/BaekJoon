#include <iostream>
#include <deque>
#include <tuple>

int tomato[102][102][102];
int day = 0; // 출력값;
int total_tomato = 0;
int good_tomato = 0;

// 0이라면 토마토가 비어있는 상태, 
// -1이라면 익지 않은 상태, 
// 1이라면 익은 상태로 바꿔서 보자.

void bfs(std::deque<std::tuple<int, int, int>>& d)
{
	if (good_tomato == total_tomato) // 이미 모든 토마토가 익어있다면. 바로 끝냄.
		return;
	if (d.empty()) // 토마토가 모두 익지 않았는데 덱이 비어버린다면, 끝냄.
		return;
	// 덱에서 토마토가 있는 위치를 뽑아내서 그 위치의 상하전후좌우를 모두 봐서 익지않은 토마토가 있다면 익힌 후 덱에 넣어줌.
	std::tuple<int, int, int> temp;
	int num = d.size();
	while (num--)
	{
		temp = d.front();
		d.pop_front();
		int m, n, h;
		std::tie(m, n, h) = temp;
		if (tomato[m - 1][n][h] == -1)
		{
			tomato[m - 1][n][h] = 1;
			good_tomato++;
			d.emplace_back(m - 1, n, h);
		}
		if (tomato[m + 1][n][h] == -1)
		{
			tomato[m + 1][n][h] = 1;
			good_tomato++;
			d.emplace_back(m + 1, n, h);
		}
		if (tomato[m][n - 1][h] == -1)
		{
			tomato[m][n - 1][h] = 1;
			good_tomato++;
			d.emplace_back(m, n - 1, h);
		}
		if (tomato[m][n + 1][h] == -1)
		{
			tomato[m][n + 1][h] = 1;
			good_tomato++;
			d.emplace_back(m, n + 1, h);
		}
		if (tomato[m][n][h - 1] == -1)
		{
			tomato[m][n][h - 1] = 1;
			good_tomato++;
			d.emplace_back(m, n, h - 1);
		}
		if (tomato[m][n][h + 1] == -1)
		{
			tomato[m][n][h + 1] = 1;
			good_tomato++;
			d.emplace_back(m, n, h + 1);
		}
	}
	day++; // 위의 과정 이후 하루가 지남.
	bfs(d);
}



int main() 
{
	// 0이라면 토마토가 비어있는 상태, 
	// -1이라면 익지 않은 상태, 
	// 1이라면 익은 상태로 바꿔서 보자.
	int M, N, H;
	std::cin >> M >> N >> H;
	std::deque<std::tuple<int, int, int>> d;
	int temp;
	for (int h = 1; h <= H; ++h)
	{
		for (int n = 1; n <= N; ++n)
		{
			for (int m = 1; m <= M; ++m)
			{
				std::cin >> temp;
				if (temp == 0)
				{
					tomato[m][n][h] = -1;
					total_tomato++;
				}
				else if (temp == 1)
				{
					tomato[m][n][h] = 1;
					d.emplace_back(m, n, h);
					total_tomato++;
					good_tomato++;
				}
				else
					tomato[m][n][h] = 0;
			}
		}
	}

	bfs(d);
	if (good_tomato == total_tomato)
		std::cout << day;
	else
		std::cout << -1;
}