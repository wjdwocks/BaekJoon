#include <iostream>
#include <vector>
#include <set>

typedef struct node
{
	node() : rainbow{ false } {}
	std::string str;
	bool rainbow;
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;
	node str;
	std::vector<node>* v = new std::vector<node>[N];
	std::set<std::string> s;

	int i = 0;
	for(int k = N; k > 0 ; k--)
	{
		std::cin >> str.str;
		v[i].emplace_back(str);
		if (str.str == "ChongChong")
			v[i][0].rainbow = true;

		std::cin >> str.str;
		v[i].emplace_back(str);
		if (str.str == "ChongChong")
			v[i][1].rainbow = true;

		i++;
	}

	s.emplace("ChongChong");
	for (int i = 0; i < N; i++) // 벡터에 넣은게 set에 있다면 같이 있는 아이도 set에 넣음.
	{
		for (std::string itr : s)
		{
			if (v[i][0].str == itr)
			{
				s.emplace(v[i][1].str);
				break;
			}
		}

		for (std::string itr : s)
		{
			if (v[i][1].str == itr)
			{
				s.emplace(v[i][0].str);
				break;
			}
		}
	}
	std::cout << s.size();
}