#include <iostream>
#include <vector>

std::vector<std::vector<int>> v;
int white_tot = 0, blue_tot = 0;

void func(int x, int y, int N) // N x N의 색종이, x, y는 색종이의 좌측 위의 x, y좌표이다. N은 크기
{
	int blue = 0, white = 0;
	
	for (int i = x; i < x + N; ++i)
	{
		for (int j = y; j < y + N; ++j)
		{
			if (v[i][j] == 1)
				blue++;
			else
				white++;
		}
	}
	if (blue == N * N)
		blue_tot++;
	else if (white == N * N)
		white_tot++;
	else
	{
		if (N == 1)
			return;
		func(x, y, N / 2);
		func(x, y + N / 2, N / 2);
		func(x + N / 2, y, N / 2);
		func(x + N / 2, y + N / 2, N / 2);
	}


}


int main()
{
	int N;
	std::cin >> N;	
	for (int i = 0; i < N; ++i)
	{
		int temptation;
		std::vector<int> temp;
		for (int j = 0; j < N; ++j)
		{
			std::cin >> temptation;
			temp.emplace_back(temptation);
		}
		v.emplace_back(temp);
	}
	func(0, 0, N);
	std::cout << white_tot << '\n' << blue_tot;

}