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
	// 끝나는 시간을 기준으로 정렬함.
	// 처음부터 끝까지 돌면서 최대로 가능한 개수를 센다.
	int finish = -1; // 현재기준 끝나는 시간	
	int result = 0; // 결과로 출력할 값.
	for (std::pair<int, int> i : v)
	{ // 다음 회의의시작 시간이 현재 끝나는 시간보다 '크면' 채택(어차피 끝나는 시간은 정렬되어 있으므로 이게 가장 빨리 끝나면서 가장 많이 고를 수 있는거임. 
		if (i.first >= finish) // 테스트 케이스만 보고 > 로 하다가 안되서 >=로 바꿔봤는데 바로 됨. 테스트 케이스좀 정성껏 작성해주면 좋겠다.
		{
			result++;
			finish = i.second;
		}
	}
	std::cout << result;
}