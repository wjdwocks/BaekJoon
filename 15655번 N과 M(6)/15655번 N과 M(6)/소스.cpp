#include <iostream>
#include <algorithm>
#include <vector>

int n, m;
int arr[9];
int isCheck[9];
std::vector<int> v;

void permu(int cursor)
{
	if (cursor == m)
	{
		for (int i = 0; i < m; i++)
			std::cout << arr[i] << ' ';
		std::cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!isCheck[i]) // arr에 없는 원소라면, 
		{
			if (cursor == 0 || v[i] > arr[cursor - 1])
			{
				arr[cursor] = v[i];
				isCheck[i] = true;
				permu(cursor + 1);
				isCheck[i] = false;
			}
		}
	}
}

int main()
{
	std::cin >> n >> m;
	int temp;
	for (int i = 0; i < n; i++)
	{
		std::cin >> temp;
		v.emplace_back(temp);
	}
	std::sort(v.begin(), v.end());

	permu(0);
}