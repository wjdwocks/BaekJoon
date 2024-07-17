#include <iostream>
#include <deque>
#include <tuple>

int tomato[102][102][102];
int day = 0; // ��°�;
int total_tomato = 0;
int good_tomato = 0;

// 0�̶�� �丶�䰡 ����ִ� ����, 
// -1�̶�� ���� ���� ����, 
// 1�̶�� ���� ���·� �ٲ㼭 ����.

void bfs(std::deque<std::tuple<int, int, int>>& d)
{
	if (good_tomato == total_tomato) // �̹� ��� �丶�䰡 �;��ִٸ�. �ٷ� ����.
		return;
	if (d.empty()) // �丶�䰡 ��� ���� �ʾҴµ� ���� �������ٸ�, ����.
		return;
	// ������ �丶�䰡 �ִ� ��ġ�� �̾Ƴ��� �� ��ġ�� ���������¿츦 ��� ���� �������� �丶�䰡 �ִٸ� ���� �� ���� �־���.
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
	day++; // ���� ���� ���� �Ϸ簡 ����.
	bfs(d);
}



int main() 
{
	// 0�̶�� �丶�䰡 ����ִ� ����, 
	// -1�̶�� ���� ���� ����, 
	// 1�̶�� ���� ���·� �ٲ㼭 ����.
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