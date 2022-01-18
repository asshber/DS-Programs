#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node()
	{
		data = 0;
		next = NULL;
	}
};

class Linkedlist
{
public:
	Node* head;
	Linkedlist()
	{
		head = NULL;
	}
	int getlength()
	{
		int counter = 0;
		Node* temp = head;
		while (temp != NULL)
		{
			counter++;
		}
		return counter;
	}
	void insertNode(int d)
	{
		Node* obj = new Node();
		if (head == NULL)
		{
			head = obj;
			obj->data = d;
			return;
		}
		Node* tail = head;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = obj;
		obj->data = d;
	}
	void print()
	{
		Node* tail = head;
		while (tail != NULL)
		{
			cout << tail->data << "->";
			tail = tail->next;
		}
		cout << endl;
	}

	void SelectionSort()
	{
		Node* h = head, * i, * j, * next_i;
		for (i = h; i != NULL && i->next != NULL; i = i->next)
		{
			Node* min;
			min = i;
			for (j = i->next; j != NULL; j = j->next)
			{
				if (j->data < min->data)
					min = j;
			}
			if (min != i)
			{
				swap(i, min);
			}
		}
		head = h;
	}
	void swap(Node* i, Node* min)
	{
		Node* prev1=head;
		Node* prev2=head;
		Node* temp;
		Node* it=head;
		while (it->data!=i->data)
		{
			prev1 = it;
			it = it->next;
		}
		it = head;
		while (it->data!=min->data)
		{
			prev2 = it;
			it = it->next;
		}
		prev1->next = min;
		prev2->next = i;
		temp = i->next;
		i->next = min->next;
		min->next = temp;
	}
};

int main()
{
	Linkedlist s;
	s.insertNode(4);
	s.insertNode(8);
	s.insertNode(5);
	s.insertNode(1);
	s.insertNode(3);
	s.insertNode(9);
	s.print();
	s.SelectionSort();
	s.print();
}