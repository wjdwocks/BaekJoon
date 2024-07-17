#include <iostream>
#include <cmath>
#include <queue>

int main(void)
{
	std::queue<int> q;
	int n;
	while (1)
	{
		std::cin >> n;
		if (n == -1)
			break;
		int limit = std::sqrt(n);
		int temp = 0;
		for (int i = 1; i <= n / 2; i++)
		{
			if (n % i == 0)
			{
				temp += i;
				q.push(i);
			}
		}
		if (temp == n)
		{
			std::cout << n << " = ";
			while (!q.empty())
			{
				std::cout << q.front();
				q.pop();
				if(!q.empty())
				std::cout <<  " + ";
			}
		}
		else
		{
			std::cout << n << ' ' << "is NOT perfect.";
		}
		if (!q.empty())
		{
			while (!q.empty())
				q.pop();
		}
		std::cout << std::endl;
	}

}