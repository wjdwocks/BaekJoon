#include <iostream>
#include <vector>
#include <queue>
#include <stack>

int main()
{
	int N, num;
	std::cin >> N;
	std::stack<int> s1;
	std::queue<int> q1;
	for (int i = 0; i < N; i++)
	{
		std::cin >> num;
		q1.emplace(num);
	}
	int cursor = 1;
	while (cursor <= N)
	{
		if (q1.empty())
		{
			if (s1.top() == cursor)
			{
				s1.pop();
				cursor++;
				continue;
			}
			else
			{
				std::cout << "Sad";
				return 0;
			}
		}
		if (q1.front() == cursor)
		{

			q1.pop();
			cursor++; 
		}
		else if (!s1.empty() && s1.top() == cursor)
		{
			s1.pop();
			cursor++;
		}
		else
		{
			s1.emplace(q1.front());
			q1.pop();
		}

	}
	std::cout << "Nice";


}