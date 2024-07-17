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
			if (s.size() == 0) // ����ִٸ�
			{
				s.emplace(arr[i]);
				break;
			}
			if (arr[i].num > s.top().num) // ������ ���� �� top���� �� ũ�� 
			{
				result[s.top().order] = arr[i].num;
				s.pop(); // pop�ϰ� �ѹ� �� ��
				continue;
			}
			else // top���� �� �۰ų� ���ٸ�
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

