#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	int N, M;
	std::cin >> N >> M;

	std::vector<int> v(N);

	for (int i = 0; i < N; ++i)
		std::cin >> v[i];
	std::sort(v.begin(), v.end());

	std::vector<std::vector<int>> result;
	int cnt = 0;

	// N���� ���� ����ִ� �� ���� v���� M���� ��� ������ ������ ��.
	// �ٵ� M�� ������� 
	std::vector<int> cursor(M); // cursor�� ������ ���� ����.

	for (int i = 0; i < M; ++i)
		cursor[i] = i; // Ŀ������ v[0]�� ��� ����Ű�� �ؼ� ���� ���� �ε����� ��ŰŰ�� �ִ� cursor�� �ִٸ� continue;�ϰ�
	// �ƴ϶�� �׷��� ������� �ε������� ���ͷ� �ϳ� ���� ���� result�� push��.

	while (1) // �ϴ� ���ѹݺ�
	{
		if (cursor[M-1] == N)
			break;


		std::vector<int> temp; // �����ϳ��� �ӽ÷� �����
		for (int i = 0; i < M; ++i)
			temp.emplace_back(v[cursor[i]]); // �� �ε����� �ش��ϴ� ���� ���� ��
		result.emplace_back(temp); // �� ���͸� result�� �־ ����.



		cursor[M - 1]++; // �� ������ Ŀ���� ���� 1 �ø�.
		for (int i = M - 1; i >= 1; --i) // cursor[1]������ �ϰ�, cursor[0]�� cursor[1]�� ���ؼ��� �پ��ų� �״�ΰų� ��.
		{
			if (cursor[i] == N) // ������ Ŀ���� N�� �Ǹ� �迭�� ũ�⸦ ����� 0���� �������.
			{
				cursor[i - 1]++;
				cursor[i] = cursor[i-1]+1;
			}
			// ���� �ݺ������� ��� �ø� ���� N�� �� �� ���̾� �ݺ���.
		}
	}

	std::sort(result.begin(), result.end());
	for (auto itr = result.begin(); itr != result.end(); ++itr)
	{
		if (itr != result.begin() && *itr == *(itr - 1))
			continue;
		for (int i : *itr)
			std::cout << i << ' ';
		std::cout << '\n';
	}
}
