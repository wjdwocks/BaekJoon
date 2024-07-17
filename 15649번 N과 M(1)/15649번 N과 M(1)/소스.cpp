#include <iostream>

void permu(int cursor, int* arr, bool* isVisited, int n, int m)
{
	if (cursor == m) // 순열의 갯수가 다 차면
	{
		for (int i = 0; i < m; i++)
			std::cout << arr[i] << " ";
		std::cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (isVisited[i] == false)
		{
			isVisited[i] = true; // arr의 cursor위치에 i를 넣고 방문했다고 체크.
			arr[cursor] = i;
			permu(cursor + 1, arr, isVisited, n, m); // 체크된 isVisited가 넘어가니 중복은 안됨.
			isVisited[i] = false;
		}
	}
}

int main()
{
	int n, m;
	std::cin >> n >> m;

	int arr[9]; // 1~8을 사용할 것이기 때문.
	bool isVisited[9] = { false };

	permu(0, arr, isVisited, n, m);
}