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

	// N개의 수가 들어있는 저 벡터 v에서 M개씩 골라서 수열을 만들어야 함.
	// 근데 M이 몇개인지를 
	std::vector<int> cursor(M); // cursor는 선택할 것의 개수.

	for (int i = 0; i < M; ++i)
		cursor[i] = i; // 커서들이 v[0]를 모두 가리키게 해서 서로 같은 인덱스를 가키키고 있는 cursor가 있다면 continue;하고
	// 아니라면 그렇게 만들어진 인덱스들을 벡터로 하나 만들어서 위의 result에 push함.

	while (1) // 일단 무한반복
	{
		if (cursor[M-1] == N)
			break;


		std::vector<int> temp; // 벡터하나를 임시로 만들고
		for (int i = 0; i < M; ++i)
			temp.emplace_back(v[cursor[i]]); // 각 인덱스에 해당하는 값을 넣은 뒤
		result.emplace_back(temp); // 그 벡터를 result에 넣어서 보관.



		cursor[M - 1]++; // 맨 마지막 커서의 값을 1 늘림.
		for (int i = M - 1; i >= 1; --i) // cursor[1]까지만 하고, cursor[0]은 cursor[1]에 의해서만 줄어들거나 그대로거나 함.
		{
			if (cursor[i] == N) // 마지막 커서가 N이 되면 배열의 크기를 벗어나니 0으로 만들어줌.
			{
				cursor[i - 1]++;
				cursor[i] = cursor[i-1]+1;
			}
			// 다음 반복에서는 방금 늘린 수가 N이 될 때 뒤이어 반복함.
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
