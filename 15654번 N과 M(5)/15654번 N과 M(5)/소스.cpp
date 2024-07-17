#include <iostream>
#include <algorithm>
#include <vector>

int m, n;
std::vector<int> v;
int arr[9];
bool isCheck[9] = { false };

void permu(int cursor)
{
	if (cursor == n)
	{
		for (int i = 0; i < n; i++)
			std::cout << arr[i] << ' ';
		std::cout << '\n';
		return;
	}
	for (int i = 0; i < m; i++)
	{
		if (!isCheck[i])
		{
			arr[cursor] = v[i];
			isCheck[i] = true;
			permu(cursor + 1);
			isCheck[i] = false;
		}
	}
}

int main()
{
	std::cin >> m >> n;
	int temp;
	
	for (int i = 0; i < m; i++)
	{
		std::cin >> temp;
		v.emplace_back(temp);
	}
	std::sort(v.begin(), v.end());

	permu(0);
}