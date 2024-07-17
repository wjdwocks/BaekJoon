#include <iostream>
#include <stack>
#include <string>

int main()
{
	std::stack<double> s;
	int N;
	std::cin >> N;

	std::string str;
	std::cin >> str;

	double* arr = new double[N] {0};
	
	for (int i = 0; i < N; i++)
		std::cin >> arr[i];

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			s.push(arr[str[i]-65]);
		}
		else
		{
			double temp2 = s.top();
			s.pop();
			double temp1 = s.top();
			s.pop();
			if (str[i] == '+')
				s.push(temp1 + temp2);
			else if (str[i] == '-')
				s.push(temp1 - temp2);
			else if (str[i] == '*')
				s.push(temp1 * temp2);
			else if (str[i] == '/')
				s.push(temp1 / temp2);
		}
	}

	printf("%.2lf", s.top());


}