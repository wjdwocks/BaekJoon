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

void func(int M, int N, int x, int y) // 키잉으로 얼마인가.
{
	// x == 3이라면 3, M+3, 2M+3, 3M+3 ... 을 해서 nM+3이 M과 N의 최소공배수를 넘기기 전까지 맞는 y가 찾아지면 그게 답 아니라면 -1출력
	// 최소공배수를 먼저 구해야함.
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
// 즉, M과 x를 보고 x가 될 수 있는 년도들을 추출해서, 각 년도마다의 y'값을 확인해봄.
// 그 y'값이 찾고자 하는 y값이라면 그때의 년도를 출력하고, 년도가 M과 N의 최소공배수를 넘는다면 재앙이 찾아온거임.


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