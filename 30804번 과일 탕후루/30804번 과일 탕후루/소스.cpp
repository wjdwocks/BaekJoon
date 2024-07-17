#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, temp;
	std::cin >> N;

	if (N <= 2)
	{
		std::cout << N;
		return 0;
	}
	
	std::vector<int> v;

	int* dp = new int[N + 1];

	while (N--) // O(n)
	{
		std::cin >> temp;
		v.emplace_back(temp);
	}
	
	int first = v[0], second = v[0] == v[1] ? 0 : v[1], cnt = 2; // 첫번쨰 탕후루 종류, 두 번째 탕후루 종류, 마지막으로 이어진 과일의 개수와 종류, 이번 탕후루의 과일개수
	std::pair<int, int> last_fruit = v[0] == v[1] ? std::make_pair(v[0], 2) : std::make_pair(v[1], 1); // 종류, 개수

	std::vector<int> result;

	for (auto itr = v.begin() + 2; itr != v.end(); ++itr)
	{
		if (second == 0) // 아직까지 과일 종류가 1개임.
		{
			if (*itr == first) // 계속 한가지 과일만 나와서 지금까지 종류가 1개인 경우
			{
				cnt++;
				last_fruit.second++;
				continue;
			}
			else // 두번쨰 종류 과일이 나온 경우
			{
				cnt++;
				second = *itr;
				last_fruit.first = *itr;
				last_fruit.second = 1;
			}
		}
		else
		{
			if (*itr == second) // 뒤에 나온 과일과 같은 과일인 경우
			{
				cnt++;
				last_fruit.second++;
				continue;
			}
			else if (*itr == first) // 앞에 나온 과일과 같은 과일인 경우
			{
				cnt++;
				std::swap(first, second);
				last_fruit.first = *itr;
				last_fruit.second = 1;
			}
			else // 새로운 3번째 과일이 나온 경우.
			{
				result.emplace_back(cnt);
				first = last_fruit.first;
				cnt = last_fruit.second; // 다음 두개 셀 때 시작할 cnt값.
				last_fruit.first = *itr; // 새로운 친구
				last_fruit.second = 1; // 새로운 친구 1
				second = *itr; // 이 새로운 친구가 이제 second임.
				cnt++; // 새로운 친구도 세줘야 함.
			}
		}

	}
	result.emplace_back(cnt);
	std::sort(result.begin(), result.end(), [](int a, int b) {return a > b; });
	std::cout << result[0];
}