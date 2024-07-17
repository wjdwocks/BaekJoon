#include <iostream>
#include <algorithm>

int N, ret = 0;
int* days = new int[N+1];
int* pays = new int[N+1];

int func(int day, int temp)
{
	if (day > N + 1) // N������ �Ѿ�ٸ� ���� ���缭 �ִ밡 �ƴϰ� �ϱ�.
		return ret;
	
	ret = temp;
	return std::max(func(day + days[day], temp + pays[day]), func(day + 1, temp + 0));
}

int main()
{
	std::cin >> N;
	for (int i = 1; i <= N; i++)
	{
		std::cin >> days[i] >> pays[i];
	}
	ret = func(1, 0);
	std::cout << ret;

}