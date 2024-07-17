#include <iostream>
#include <deque>
#include <vector>

std::vector<std::pair<int, int>> sadari;
std::vector<std::pair<int, int>> snake;

bool Visit[101] = { true, false, };

int check_item(int now)
{
	for (std::pair<int, int> i : sadari)
	{
		if (i.first == now)
			return i.second;
	}
	for (std::pair<int, int> i : snake)
	{
		if (i.first == now)
			return i.second;
	}
	return now;
}

void bfs()
{
	std::deque<std::pair<int ,int>> d; // 현재 칸, 던진 횟수.
	d.emplace_back(1, 0);
	Visit[1] = true;
	while (!d.empty())
	{
		int now = d.front().first;
		int count = d.front().second;
		d.pop_front();

		if (now == 100)
			std::cout << count;

		// 주사위를 1~6까지 굴렸을 때 도착할 곳이 이미 방문한 곳인지 확인하고, 
		// 방문하지 않았다면 큐에 넣어준다.
		// 근데 만약 뱀이나 사다리가 시작되는 위치라면, 다음 위치 또한 방문처리를 해주어야 할듯.
	

		// 6굴렸을 때
		if (now + 6 <= 100 && !Visit[now + 6])
		{
			Visit[now + 6] = true;
			Visit[check_item(now + 6)] = true;
			d.emplace_back(check_item(now + 6), count + 1);
		}
		// 5굴렸을 때
		if (now + 5 <= 100 && !Visit[now + 5])
		{
			Visit[now + 5] = true;
			Visit[check_item(now + 5)] = true;
			d.emplace_back(check_item(now + 5), count + 1);
		}
		// 4굴렸을 때
		if (now + 4 <= 100 && !Visit[now + 4])
		{
			Visit[now + 4] = true;
			Visit[check_item(now + 4)] = true;
			d.emplace_back(check_item(now + 4), count + 1);
		}
		// 3굴렸을 때
		if (now + 3 <= 100 && !Visit[now + 3])
		{
			Visit[now + 3] = true;
			Visit[check_item(now + 3)] = true;
			d.emplace_back(check_item(now + 3), count + 1);
		}

		// 2굴렸을 때
		if (now + 2 <= 100 && !Visit[now + 2])
		{
			Visit[now + 2] = true;
			Visit[check_item(now + 2)] = true;
			d.emplace_back(check_item(now + 2), count + 1);
		}

		// 1굴렸을 때
		if (now + 1 <= 100 && !Visit[now + 1])
		{
			Visit[now + 1] = true;
			Visit[check_item(now + 1)] = true;
			d.emplace_back(check_item(now + 1), count + 1);
		}

	}
	return;
}


int main()
{
	int N, M;
	std::cin >> N >> M;

	int first, last;

	for (int i = 0; i < N; i++)
	{
		std::cin >> first >> last;
		sadari.emplace_back(first, last);
	}

	for (int i = 0; i < M; ++i)
	{
		std::cin >> first >> last;
		snake.emplace_back(first, last);
	}

	bfs();

}