#include <iostream>
#include <algorithm>
#include <vector>
#include <map>


int n, m;
std::vector<int> v;
int arr[9];

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
		arr[cursor] = v[i];
		permu(cursor + 1);
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