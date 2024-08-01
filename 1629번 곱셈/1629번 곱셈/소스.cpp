#include <iostream>
#include <cmath>

long long A, B, C;

// A의 B승이므로 B를 계속 반으로 나누어서 분할정복하여 지수를 나눈 뒤 각 수를 %C하며 합친다. 

long long func(long long n)
{
	// 여기에서 재귀를 이용하여 지수를 분할 정복알고리즘을 이용해 1이 될 때 까지 제곱수를 나누고, 다시 합치면서 올라간다.
	if (n == 1) return A % C; // 더이상 작아질 수 없다면 아무것도 제곱하지 않은 A를 C로 나눈 나머지를 반환.
	long long k = func(n / 2) % C; // n이 반으로 더 나누어질 수 있는 지수라면 계속해서 반으로 나눈 뒤 C로 나눈 나머지가 되도록 함.
	// 그렇게 해서 func(n / 2)의 값이 결정이 되었다면 그에 따른 k값을 통해 윗 단계(현재 기준 n이 반으로 나누어지기 전)의 func(n/2)를 return해준다.
	if (n % 2 == 0) return k * k % C; // 만약 짝수였다면 같은 수를 곱할것이고
	else return k * k % C * A % C; // 만약 홀수였다면 같은 수에 1을 더한 지수값이었을 것임.
}


int main()
{
	std::cin >> A >> B >> C;	
	std::cout << func(B);
}