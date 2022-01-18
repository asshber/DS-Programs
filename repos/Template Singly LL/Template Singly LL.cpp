#include <iostream>
using namespace std;
 
template<typename T>
class Node
{
public:
	T data;
	Node* next;
	Node(T x)
	{
		data = x;
		next = NULL;
	}
};
template<typename T>
class SLL
{
public:
	Node<T>* head;
	SLL()
	{
		head = NULL;
	}
	void insertnode(T x)
	{
		Node<T>* newnode = new Node<T>(x);
		if (head == NULL)
		{
			head = newnode;
		}
		else
		{
			Node<T>* temp; 
			for (temp = head; temp->next != NULL; temp = temp->next);
			temp->next = newnode;
		}
	}
	void insertnode(int pos, T x)
	{
		int size=0;
		Node<T>* temp;
		for (temp = head; temp != NULL; temp = temp->next,size++);
		if (!(pos > 0 || pos <= size))
		{
			cout << "\nYou entered Invalid pos.";
			exit(1);
		}
		else
		{
			Node<T>* newnode = new Node<T>(x);
			if (pos == 1)
			{
				newnode->next = head;
				head = newnode;
				return;
			}
			else if (pos == size)
			{
				(*this).insertnode(x);
				return;
			}
			else
			{
				int i;
				temp = head;
				for (i=1 ; i<pos-1; temp = temp->next,i++);
				newnode->next = temp->next;
				temp->next = newnode;
				return;
			}
		}
	}
	void display()
	{
		Node<T>* temp;
		for (temp = head; temp != NULL; temp = temp->next)
		{
			cout << temp -> data << endl;
		}
	}
};
int main()
{
	SLL<char> l1;
	l1.insertnode('a');
	l1.insertnode('c');
	l1.insertnode('d');
	l1.insertnode(2, 'b');
	l1.display();
}
