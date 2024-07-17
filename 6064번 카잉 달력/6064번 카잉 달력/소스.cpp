#include <iostream>
#include <algorithm>

int func2(int a, int b)
{
	if (std::min(a, b) == 0)
		return std::max(a, b);
	if (a > b)
		return func2(a - b, b);
	else
		return func2(b - a, a);
}

void func(int M, int N, int x, int y) // Ű������ ���ΰ�.
{
	// x == 3�̶�� 3, M+3, 2M+3, 3M+3 ... �� �ؼ� nM+3�� M�� N�� �ּҰ������ �ѱ�� ������ �´� y�� ã������ �װ� �� �ƴ϶�� -1���
	// �ּҰ������ ���� ���ؾ���.
	int max = M * N / func2(M, N);
	int result = x;
	while (result <= max)
	{
		if (y == result % N || (y == N && (result % N == 0)))
		{
			std::cout << result << '\n';
			return;
		}
		result += M;
	}
	std::cout << -1 << '\n';
}
// ��, M�� x�� ���� x�� �� �� �ִ� �⵵���� �����ؼ�, �� �⵵������ y'���� Ȯ���غ�.
// �� y'���� ã���� �ϴ� y���̶�� �׶��� �⵵�� ����ϰ�, �⵵�� M�� N�� �ּҰ������ �Ѵ´ٸ� ����� ã�ƿ°���.


int main()
{
	int T;
	std::cin >> T;
	int M, N, x, y;
	for (int i = 0; i < T; ++i)
	{
		std::cin >> M >> N >> x >> y;
		func(M, N, x, y);
	}
}