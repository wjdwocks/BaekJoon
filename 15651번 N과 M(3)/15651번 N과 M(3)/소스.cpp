#include <iostream>

int n, m;
int arr[9];

void permu(int cursor)
{
	if (cursor == m) // °¹¼ö
	{
		for (int i = 0; i < m; i++)
		{
			std::cout << arr[i] << ' ';
		}
		std::cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		arr[cursor] = i;
		permu(cursor + 1);
	}
}

int main()
{
	std::cin >> n >> m;

	permu(0);
}