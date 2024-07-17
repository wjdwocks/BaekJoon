#include <iostream>

int n, m;
int arr[9];

void permu(int cursor, int min)
{
	if (cursor == m)
	{
		for (int i = 0; i < m; i++)
			std::cout << arr[i] << " ";
		std::cout << '\n';
		return;
	}
	for (int i = min; i <= n; i++)
	{
		arr[cursor] = i;
		permu(cursor + 1, i);
	}
}

int main()
{
	std::cin >> n >> m;

	permu(0, 1);
}