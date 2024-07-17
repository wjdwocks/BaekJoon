#include <iostream>
#include <vector>



int main()
{
	std::vector<int> v;
	int N, M;
	std::cin >> N >> M;

	bool* arr = (bool*)calloc(N + 1, sizeof(bool)); // false
	
	int cursor = 0;
	int result = 0;
	std::cout << '<';
	while (result != N)
	{
		for (int i = 0; i < M; i++)
		{
			if (cursor == N + 1)
				cursor = cursor - N;

			cursor += 1;
			if (cursor == N + 1)
				cursor = cursor - N;

			if (arr[cursor] == true)
			{
				i--;
				continue;
			}

			if (cursor == N + 1)
				cursor = cursor - N;
		}
		std::cout << cursor;
		arr[cursor] = true;
		result++;
		if (result == N)
			break;
		std::cout << ", ";
		
	}
	std::cout << '>';
}