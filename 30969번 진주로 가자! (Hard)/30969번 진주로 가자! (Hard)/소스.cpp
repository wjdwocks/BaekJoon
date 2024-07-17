#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	bool jinju = false;
	std::vector<short> v;
	std::string temp;
	long long price, max = 0, result = 0;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> temp >> price;
		if (jinju)	// ���ְ� �̹� ���Դٸ� �ٷ� �� ū�� Ȯ��
			result = price > max ? result + 1 : result;
		else		// �ƴ϶�� ���Ϳ� �� ������ �ϴ� ����. �׷��� temp�� jinju���� Ȯ��.
		{
			if (temp == "jinju")
			{
				jinju = true;
				max = price;
			}
			else
			{
				if (price > 1000)
					result++;
				else
					v.emplace_back(price);
			}
		}
	}
	
	for (auto i : v)
	{
		if (i > max)
			result++;
	}
	std::cout << max << std::endl << result;
}