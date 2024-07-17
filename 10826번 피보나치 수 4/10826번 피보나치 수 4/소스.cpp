#include <iostream>
#include <algorithm>

typedef struct node
{
	std::string str;
	int length;
};

std::string string_plus(node mynode1, node mynode2)
{
	int length1 = mynode1.str.length();
	int length2 = mynode2.str.length();
	int max = std::max(mynode1.str.length(), mynode2.str.length());
	char* arr = new char[max + 1];
	arr[max] = 0;
	for (int i = 0; i < max; i++)
	{
		if (length1 >= 1 && length2 >= 1)
			arr[i] = mynode1.str[length1-- - 1] - 48 + mynode2.str[length2-- - 1] - 48;
		else if (length1 == 0)
			arr[i] = mynode2.str[length2-- - 1] - 48;
		else if (length2 == 0)
			arr[i] = mynode1.str[length1-- - 1] - 48;
		else
			std::cout << "Error";
	}
	for (int i = 0; i < max; i++)
	{
		if (arr[i] >= 10)
		{
			arr[i + 1]++;
			arr[i] = arr[i] - 10;
		}
	}
	std::string str(arr);
	std::reverse(str.begin(), str.end());

	return str;
}
// ���� �迭�� �Ǻ���ġ ���� ������. ���ؼ�. ������� ���� ¥���� �׳� ��Ʈ�� �ν������� �ͳ�

int main()
{
	int n;
	std::cin >> n;

	node* mynode = new node[10001];
	mynode[0].str = "0";
	mynode[1].str = "1";

	for (int i = 2; i < 10001; i++)
	{
		mynode[i].str = string_plus(mynode[i-2], mynode[i-1]);
	}
	std::cout << mynode[n].str;

}