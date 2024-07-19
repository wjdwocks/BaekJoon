#include <iostream>
#include <deque>


long long A, B;

std::deque<long long> results;

void bfs()
{
	std::deque<std::pair<long long, long long>> d;
	d.emplace_back(A, 1);
	while (!d.empty())
	{
		long long now = d.front().first, result = d.front().second;
		d.pop_front();
		if (now == B)
		{
			std::cout << result;
			return;
		}
		if (10 * now + 1 <= B)
			d.emplace_back(now * 10 + 1, result + 1);
		if (now * 2 <= B)
			d.emplace_back(now * 2, result + 1);
	}
	std::cout << -1;
	return;

}

int main()
{
	std::cin >> A >> B;
	bfs();
}