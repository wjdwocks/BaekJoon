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
		if (jinju)	// 진주가 이미 나왔다면 바로 더 큰지 확인
			result = price > max ? result + 1 : result;
		else		// 아니라면 벡터에 그 가격을 일단 넣음. 그러고 temp가 jinju인지 확인.
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