#include <iostream>
#include <vector>
#include <cmath>

// (x, y)는 좌측 위 좌표, first, last는 그 네모에 포함되는 수들. length는 네모의 변 길이 r, c는 타겟값.
int func(int x, int y, int first, int last, int length, int r, int c)
{
	if (length == 1)
	{
		return first;
	}
	if (r < length / 2 && c < length / 2) // 좌측 위 네모
	{
		return func(x, y, first, last/4, length/2, r, c);
	}
	else if (r < length / 2 && c >= length / 2) // 우측 위 네모
	{
		int next_first = first + pow(length, 2) / 4;
		return func(x, y + length / 2, next_first, next_first + pow(length/2, 2) - 1, length / 2, r, c - length/2);
	}
	else if (r >= length / 2 && c < length / 2) // 죄측 아레 네모
	{
		int next_first = first + pow(length, 2) / 2;
		return func(x + length / 2, y, next_first, next_first + pow(length/2, 2) - 1, length / 2, r - length/2, c);
	}
	else // 우측 아레 네모
	{
		int next_first = first + pow(length, 2) * 3 / 4;
		return func(x + length / 2, y + length / 2, next_first, next_first + pow(length/2, 2) - 1, length / 2, r - length / 2, c - length / 2);
	}
}


int main()
{
	int N, r, c;
	std::cin >> N >> r >> c;
	N = int(std::pow(2, N));
	int start = 0, last = pow(N, 2) - 1;
	std::cout << func(0, 0, start, last, N, r, c);

}
