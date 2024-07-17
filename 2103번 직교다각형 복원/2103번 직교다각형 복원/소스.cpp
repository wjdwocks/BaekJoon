#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int N;
	std::cin >> N;
	std::vector<std::pair<int, int>> p(N);
	for (int i = 0; i < N; ++i)
		std::cin >> p[i].first >> p[i].second;

	int result = 0;
	// x�� �� y�� ������ �����غ��� ���� x��� �ڿ��� - �տ���
	// ���� y��� �ڿ��� - �տ��� �� ���ϸ� �ɵ�.
	std::sort(p.begin(), p.end(), [](std::pair<int, int> one, std::pair<int, int> two) {
		if (one.first == two.first)
			return one.second < two.second;
		return one.first < two.first; });
	for (int i = 0; i < N; i+=2)
		result += p[i + 1].second - p[i].second;
	std::sort(p.begin(), p.end(), [](std::pair<int, int> one, std::pair<int, int> two) {
		if (one.second == two.second)
			return one.first < two.first;
		return one.second < two.second; });
	for (int i = 0; i < N; i += 2)
		result += p[i + 1].first - p[i].first;
	std::cout << result;
}