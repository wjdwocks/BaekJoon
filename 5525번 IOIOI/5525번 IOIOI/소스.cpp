#include <iostream>

int main()
{
	int N, M;
	std::cin >> N;
	std::cin >> M;
	std::string S;
	std::cin >> S;
	int length = 0;
	bool IOI = false;
	int result = 0;
	// ���ڿ��� �˻��ؼ� IOIOIOI�� �������� ������ �װŸ� ĳġ�ϰ�, ó���� ���� ���̸� ���� �װŶ� N�̶� ���ؼ� ������ ��ü�� ���ϰ� �ݺ�.
	for (int i = 0; i <= M; ++i)
	{
		if (IOI == false && S[i] == 'I') // IOI�� �̾����� �ʰ� �ְ�, ó������ I�� ������
		{
			IOI = true;
			length++;
		}
		else if (IOI == true && S[i] != S[i - 1] && S[i] != NULL)
			length++;
		else if (IOI == true && S[i] == S[i - 1] && S[i-1] == 'O')
		{
			length -= 1;
			length /= 2; // �� �� length�� O�� ����. 
			int temp = length + 1 - N;
			if (temp < 0)
				temp = 0;
			result += temp;
			length = 0;
			IOI = false;
		}
		else if (IOI == true && S[i] == S[i - 1] && S[i-1] == 'I')
		{
			length /= 2;
			int temp = length + 1 - N;
			if (temp < 0)
				temp = 0;
			result += temp;
			length = 1;
		}
		else if (IOI == true && S[i] == NULL && S[i-1] == 'I')
		{
			length /= 2;
			int temp = length + 1 - N;
			if (temp < 0)
				temp = 0;
			result += temp;
			length = 0;
			IOI = false;
		}
		else if (IOI == true && S[i] == NULL && S[i - 1] == 'O')
		{
			length -= 1;
			length /= 2;
			int temp = length + 1 - N;
			if (temp < 0)
				temp = 0;
			result += temp;
			length = 0;
			IOI = false;
		}
	}
	std::cout << result;
}