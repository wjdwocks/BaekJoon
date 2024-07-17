#include <iostream>

bool arr[1000] = { true, true,  };

bool check(int i, int temp, int strike, int ball)
{
	// 각 i와 temp의 자릿수를 파악함.
	int a1 = i / 100, c1 = i % 10, b1= i / 10 - a1 * 10; // a는 100자리수, b는 10자리수, c는 1자리수
	int a2 = temp / 100, c2 = temp % 10, b2 = temp / 10 - a2 * 10; // a는 100자리수, b는 10자리수, c는 1자리수
	// 이 i와 temp와의 strike와 ball을 체크함.
	int strike_i = 0, ball_i = 0;
	if (a1 == a2)
		strike_i++;
	if (b1 == b2)
		strike_i++;
	if (c1 == c2)
		strike_i++;
	if (a1 == b2 || a1 == c2)
		ball_i++;
	if (b1 == a2 || b1 == c2)
		ball_i++;
	if (c1 == a2 || c1 == b2)
		ball_i++;
	// 마지막으로 이 i와 temp와의 strike, ball과 제시된 strike, ball을 비교해서 가능성이 있다면 true, 아니라면 false를 반환함.
	if (strike_i == strike && ball_i == ball)
		return true;
	else
		return false;

}

int main()
{
	int N;
	std::cin >> N;
	int temp, strike, ball, result = 0;
	for (int i = 0; i <= 999; ++i)
	{
		arr[i] = true;
		int a = i/100, c = i%10, b = i/10 - a*10; // a는 100자리수, b는 10자리수, c는 1자리수
		if (a == 0 || b == 0 || c == 0)
			arr[i] = false;
		else if (a == b || b == c || a == c)
			arr[i] = false;
	}

	while(N--) {
		std::cin >> temp >> strike >> ball;
		for (int i = 123; i <= 987; ++i)
		{
			if(arr[i] == true)
				arr[i] = check(i, temp, strike, ball);
		}
	}

	for (int i = 123; i <= 987; ++i)
	{
		if (arr[i] == true)
			result++;
	}
	std::cout << result;
}