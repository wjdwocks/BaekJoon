#include <iostream>

int n, m;
int arr[9];
bool isCheck[9] = { false };

void permu(int count, int min)
{
	if (count == m) // 마지막 순서라면
	{
		for (int i = 0; i < m; i++)
			std::cout << arr[i] << " ";
		std::cout << '\n';
		return;
	}
	for (int i = min; i <= n; i++)
	{
		if (!isCheck[i])
		{
			arr[count] = i;
			isCheck[i] = true;
			permu(count + 1, i);
			isCheck[i] = false;
		}
	}
}


int main()
{
	std::cin >> n >> m;

	permu(0,1);
}