
#include <iostream>
using namespace std;
class Node
{
public:
	Node* prev;
	Node* next;
	int data;
	Node()
	{
		prev = NULL;
		next = NULL;
	}
	Node(int x)
	{
		prev = NULL;
		next = NULL;
		data = x;
	}
};
class Doubly
{
	Node* head;
	Node* tail;
public:
	Doubly(int x)
	{
		Node* newnode = new Node(x);
		head = newnode;
		tail = newnode;
	}
	void insertnode(int x)
	{
		Node* temp;
		for (temp = head; temp->next != NULL; temp = temp->next);
		Node* newnode = new Node(x);
		temp->next = newnode;
		newnode->prev = temp;
		tail = newnode;
	}
	void insertnodeatpos(int pos,int x)
	{
		Node* temp;
		int count = 1;
		for (temp = head; count < pos; temp = temp->next,count++);
		if (pos == 1)
		{
			Node* newnode = new Node(x);
			newnode->next = head;
			head->prev = newnode;
			head = newnode;
			return;
		}
		else if (pos == count)
		{
			Node* newnode = new Node(x);
			newnode->prev = tail;
			tail->next = newnode;
			tail = newnode;
			return;
		}
		Node* newnode = new Node(x);
		Node* leftnode = temp->prev;
		Node* rightnode = temp->next;
		newnode->prev = leftnode;
		newnode->next = temp;
		leftnode->next = newnode;
		temp->prev = newnode;
	}
	void display()
	{
		Node* temp;
		int count = 1;
		for (temp = head; temp != NULL; temp = temp->next,count++)
		{
			cout << "Node " << count << ": " << temp->data << endl;
		}
	}
	void reversedisplay()
	{
		int count = 1;
		for (auto temp = tail; temp != NULL; temp = temp->prev)
		{
			cout << "Node " << count << ": " << temp->data << endl;
			count++;
		}
	}
	void deletenode(int pos)
	{
		int count = 0;
		Node* temp;
		for (temp = head; temp != NULL; temp = temp->next, count++);
		if (pos == 1)
		{
			temp = head;
			head = head->next;
			head->prev = NULL;
			delete temp;
			return;
		}
		else if (pos == count)
		{
			temp = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete temp;
			return;
		}
		int i = 1;
		for (temp = head; i < pos; temp = temp->next, i++);
		Node* leftnode;
		leftnode = temp->prev;
		leftnode->next = temp->next;
		Node* rightnode;
		rightnode = temp->next;
		rightnode->prev = leftnode;
		delete temp;
	}
	void reverse()
	{
		Node* cur;
		Node* next;
		cur = head;
		while (cur != NULL)
		{
			next = cur->next;
			cur->next = cur->prev;
			cur->prev = next;
			cur = next;
		}
		cur = head;
		head = tail;
		tail = cur;
	}
};
int main()
{
	Doubly l1(1);
	l1.insertnode(2);

	l1.insertnode(4);
	l1.insertnodeatpos(3, 3);
	l1.insertnodeatpos(5, 5);
	l1.insertnodeatpos(1, 0);
	l1.display();
	//l1.deletenode(2);
	cout << endl << endl;
	l1.reverse();
	l1.display();
}