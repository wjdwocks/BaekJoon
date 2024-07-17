#include <iostream>
#include <vector>
#include <deque>

// Ʈ���� �θ� ã��
// ���� �Է¹޴´�.
// bfs�� 1�� �̾��� ����� �޷�� ã�´�.

int arr[100001] = { 0, 1, 0, };

void bfs(std::vector<std::vector<int>>& v)
{
	std::deque<int> d;
	for (int i : v[1])
	{
		d.emplace_back(i);
		arr[i] = 1;
	}
	// 1�� �̾����� ������ �� ť�� �־����.
	while (!d.empty())
	{
		// ť���� �����鼭 �� ģ���� �̾����ִ� ������ Ȯ����.
		// �� ģ������ �θ� ���� d.front.second��.
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