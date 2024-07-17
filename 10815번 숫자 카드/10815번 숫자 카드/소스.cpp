#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	int N, M, temp;
	scanf("%d", &N);
	bool* arr = new bool [20000001] {false};
	bool* my = new bool [20000001] {false};
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		arr[temp + 10000000] = true;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &temp);
		if (arr[temp + 10000000] == true)
			std::cout << 1 << ' ';
		else
			std::cout << 0 << ' ';
	}
}