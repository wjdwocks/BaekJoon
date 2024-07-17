#include <iostream>
#include <vector>
#include <deque>

// 트리의 부모 찾기
// 값을 입력받는다.
// bfs로 1과 이어진 얘부터 쭈루룩 찾는다.

int arr[100001] = { 0, 1, 0, };

void bfs(std::vector<std::vector<int>>& v)
{
	std::deque<int> d;
	for (int i : v[1])
	{
		d.emplace_back(i);
		arr[i] = 1;
	}
	// 1로 이어지는 노드들을 다 큐에 넣어놓음.
	while (!d.empty())
	{
		// 큐에서 꺼내면서 그 친구랑 이어져있는 노드들을 확인함.
		// 그 친구들의 부모 노드는 d.front.second임.
		int mom = d.front();
		d.pop_front();
		for (int i : v[mom])
		{
			if (arr[i] == 0)
			{
				arr[i] = mom;
				d.emplace_back(i);
			}
		}
	}
}

int main()
{
	int N;
	std::cin >> N;

	std::vector<std::vector<int>> v(N+1);
	int first, second;
	for (int i = 0; i < N-1; ++i)
	{
		std::cin >> first >> second;
		v[first].emplace_back(second);
		v[second].emplace_back(first);
	}

	bfs(v);

	for (int i = 2; i <= N; ++i)
	{
		std::cout << arr[i] << '\n';
	}
}