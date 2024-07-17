#include <iostream>
#include <vector>
#include <cmath>

// (x, y)�� ���� �� ��ǥ, first, last�� �� �׸� ���ԵǴ� ����. length�� �׸��� �� ���� r, c�� Ÿ�ٰ�.
int func(int x, int y, int first, int last, int length, int r, int c)
{
	if (length == 1)
	{
		return first;
	}
	if (r < length / 2 && c < length / 2) // ���� �� �׸�
	{
		return func(x, y, first, last/4, length/2, r, c);
	}
	else if (r < length / 2 && c >= length / 2) // ���� �� �׸�
	{
		int next_first = first + pow(length, 2) / 4;
		return func(x, y + length / 2, next_first, next_first + pow(length/2, 2) - 1, length / 2, r, c - length/2);
	}
	else if (r >= length / 2 && c < length / 2) // ���� �Ʒ� �׸�
	{
		int next_first = first + pow(length, 2) / 2;
		return func(x + length / 2, y, next_first, next_first + pow(length/2, 2) - 1, length / 2, r - length/2, c);
	}
	else // ���� �Ʒ� �׸�
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
