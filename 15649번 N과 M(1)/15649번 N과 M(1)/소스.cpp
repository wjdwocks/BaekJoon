#include <iostream>

void permu(int cursor, int* arr, bool* isVisited, int n, int m)
{
	if (cursor == m) // ������ ������ �� ����
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
			isVisited[i] = true; // arr�� cursor��ġ�� i�� �ְ� �湮�ߴٰ� üũ.
			arr[cursor] = i;
			permu(cursor + 1, arr, isVisited, n, m); // üũ�� isVisited�� �Ѿ�� �ߺ��� �ȵ�.
			isVisited[i] = false;
		}
	}
}

int main()
{
	int n, m;
	std::cin >> n >> m;

	int arr[9]; // 1~8�� ����� ���̱� ����.
	bool isVisited[9] = { false };

	permu(0, arr, isVisited, n, m);
}