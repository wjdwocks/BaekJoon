#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, temp;
	std::cin >> N;

	if (N <= 2)
	{
		std::cout << N;
		return 0;
	}
	
	std::vector<int> v;

	int* dp = new int[N + 1];

	while (N--) // O(n)
	{
		std::cin >> temp;
		v.emplace_back(temp);
	}
	
	int first = v[0], second = v[0] == v[1] ? 0 : v[1], cnt = 2; // ù���� ���ķ� ����, �� ��° ���ķ� ����, ���������� �̾��� ������ ������ ����, �̹� ���ķ��� ���ϰ���
	std::pair<int, int> last_fruit = v[0] == v[1] ? std::make_pair(v[0], 2) : std::make_pair(v[1], 1); // ����, ����

	std::vector<int> result;

	for (auto itr = v.begin() + 2; itr != v.end(); ++itr)
	{
		if (second == 0) // �������� ���� ������ 1����.
		{
			if (*itr == first) // ��� �Ѱ��� ���ϸ� ���ͼ� ���ݱ��� ������ 1���� ���
			{
				cnt++;
				last_fruit.second++;
				continue;
			}
			else // �ι��� ���� ������ ���� ���
			{
				cnt++;
				second = *itr;
				last_fruit.first = *itr;
				last_fruit.second = 1;
			}
		}
		else
		{
			if (*itr == second) // �ڿ� ���� ���ϰ� ���� ������ ���
			{
				cnt++;
				last_fruit.second++;
				continue;
			}
			else if (*itr == first) // �տ� ���� ���ϰ� ���� ������ ���
			{
				cnt++;
				std::swap(first, second);
				last_fruit.first = *itr;
				last_fruit.second = 1;
			}
			else // ���ο� 3��° ������ ���� ���.
			{
				result.emplace_back(cnt);
				first = last_fruit.first;
				cnt = last_fruit.second; // ���� �ΰ� �� �� ������ cnt��.
				last_fruit.first = *itr; // ���ο� ģ��
				last_fruit.second = 1; // ���ο� ģ�� 1
				second = *itr; // �� ���ο� ģ���� ���� second��.
				cnt++; // ���ο� ģ���� ����� ��.
			}
		}

	}
	result.emplace_back(cnt);
	std::sort(result.begin(), result.end(), [](int a, int b) {return a > b; });
	std::cout << result[0];
}