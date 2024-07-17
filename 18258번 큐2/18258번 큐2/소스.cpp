#include <iostream>
#include <string>

class node
{
	friend class queue;
	int data;
	node* next = nullptr;
};

class queue
{
private:
	node* first = nullptr;
	node* last = nullptr;
	int size = 0;
public:
	void insert(int data)
	{
		node* newNode = new node;
		newNode->data = data;
		newNode->next = nullptr;
		size++;
		if (first == nullptr)
		{
			first = last = newNode;
			newNode->next = nullptr;
		}
		last->next = newNode;
		last = newNode;
	}

	void pop()
	{
		if (size == 0)
		{
			std::cout << -1 << '\n';
			return;
		}
		if (size == 1)
		{
			int temp = first->data;
			delete first;
			first = last = nullptr;
			std::cout << temp << '\n';
			size--;
			return;
		}
		
		int temp = first->data;
		first = first->next;
		std::cout << temp << '\n';
		size--;
	}

	void getsize()
	{
		std::cout << size << '\n';
	}

	void empty()
	{
		if (size)
			std::cout << 0 << '\n';
		else
			std::cout << 1 << '\n';
	}

	void front()
	{
		if (size == 0)
			std::cout << -1 << '\n';
		else
			std::cout << first->data << '\n';
	}

	void back()
	{
		if (size == 0)
			std::cout << -1 << '\n';
		else
			std::cout << last->data << '\n';
	}
};


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	queue q;
	int N;
	std::cin >> N;
	std::string str;
	while (N--)
	{
		std::cin >> str;
		if (str[0] == 'p' && str[1] == 'u')
		{
			int num;
			std::cin >> num;
			q.insert(num);
		}
		else if (str[0] == 'p' && str[1] == 'o')
			q.pop();
		else if (str[0] == 's')
			q.getsize();
		else if (str[0] == 'e')
			q.empty();
		else if (str[0] == 'f')
			q.front();
		else if (str[0] == 'b')
			q.back();
	}
}