#include<iostream>
#include<array>
using namespace std;
#define MAX_LIMIT 100
template<typename Key>
class Node
{
public:
	Key data;
	Node* next;
	Node(Key x)
	{
		data = x;
		next = NULL;
	}
};
template<typename Key>
class MaxPQ
{
public:
	
	Node<Key>* head;
	int limit;
	MaxPQ()
	{
		head = NULL;
		limit = MAX_LIMIT;
	}
	MaxPQ(int max)
	{
		head = NULL;
		limit = max;
	}
	bool IsEmpty()
	{
		if (head == NULL)
			return 1;
		else
			return 0;
	}
	Key max()
	{
		auto temp = head;
		for (; temp->next != NULL; temp = temp->next);
		return temp->data;
	}
	Key delmax()
	{
		auto temp = head;
		for (; temp->next->next != NULL; temp = temp->next);
		auto del = temp->next;
		temp->next = NULL;
		Key x = del->data;
		delete del;
		return x;
	}
	MaxPQ(Key a[])
	{
		for (int i = 0; i < sizeof(a) / sizeof(Key); i++)
			insert(a[i]);
	}
	void insert(Key a)
	{
		if (size() >= limit)
		{
			cout << "Queue Overflow";
			return;
		}
		Node<Key>* newnode = new Node<Key>(a);
		if (head == NULL)
		{
			head = newnode;
			return;
		}
		if (newnode->data < head->data)
		{
			newnode->next = head;
			head = newnode;
		}
		else
		{
			Node<Key>* temp = head;
			for (; (temp->next != NULL) && (newnode->data >= temp->next->data); temp = temp->next);
			newnode->next = temp->next;
			temp->next = newnode;
		}
	}
	void Display()
	{
		for (auto temp = head; temp != NULL; temp = temp->next)
			cout << temp->data << endl;
		//cout << size;
	}
	int size()
	{
		int count = 0;
		for (auto temp = head; temp != NULL; temp = temp->next, count++);
		return count;
	}
};
int main()
{
	MaxPQ<int> l1(5);
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	cout << l1.max() << endl;
	l1.Display();
	cout << endl;
	cout << l1.delmax() << endl;
	l1.Display();
}