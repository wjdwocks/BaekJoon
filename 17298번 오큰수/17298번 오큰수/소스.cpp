#include <iostream>
#include <stack>

typedef struct node
{
	int order = -1;
	int num = 0;
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::stack<node> s;

	int N;
	std::cin >> N;
	node* arr = new node[N];
	int* result = new int[N] {0 };

	for (int i = 0; i < N; i++)
	{
		std::cin >> arr[i].num;
		arr[i].order = i;
	}

	s.emplace(arr[0]);

	for (int i = 1; i < N; i++)
	{
		while (1)
		{
			if (s.size() == 0) // 비어있다면
			{
				s.emplace(arr[i]);
				break;
			}
			if (arr[i].num > s.top().num) // 다음에 들어올 게 top보다 더 크면 
			{
				result[s.top().order] = arr[i].num;
				s.pop(); // pop하고 한번 더 비교
				continue;
			}
			else // top보다 더 작거나 같다면
			{
				s.emplace(arr[i]);
				break;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (result[i] == 0)
			result[i] = -1;
		std::cout << result[i] << ' ';
	}
}

