#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;
	std::vector<std::pair<int, int>> v(N);
	int first, second;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> first >> second;
		v[i].first = first;
		v[i].second = second;
	}

	std::sort(v.begin(), v.end(), [](std::pair<int, int> first, std::pair<int, int> second) { 
		if(first.second == second.second) 
			return first.first < second.first; 
		else 
			return first.second < second.second; });
	// ������ �ð��� �������� ������.
	// ó������ ������ ���鼭 �ִ�� ������ ������ ����.
	int finish = -1; // ������� ������ �ð�	
	int result = 0; // ����� ����� ��.
	for (std::pair<int, int> i : v)
	{ // ���� ȸ���ǽ��� �ð��� ���� ������ �ð����� 'ũ��' ä��(������ ������ �ð��� ���ĵǾ� �����Ƿ� �̰� ���� ���� �����鼭 ���� ���� �� �� �ִ°���. 
		if (i.first >= finish) // �׽�Ʈ ���̽��� ���� > �� �ϴٰ� �ȵǼ� >=�� �ٲ�ôµ� �ٷ� ��. �׽�Ʈ ���̽��� ������ �ۼ����ָ� ���ڴ�.
		{
			result++;
			finish = i.second;
		}
	}
	std::cout << result;
}