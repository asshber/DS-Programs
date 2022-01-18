#include<iostream>
#include<string>
using namespace std;
class Node
{
public:
	string id;
	int time;
	int quota;
	Node* next;
	Node(string a,int t,int q)
	{
		next = NULL;
		id = a;
		time = t;
		quota = q;
	}
};
class LinkedList
{
public:
	Node* head;
	Node* tail;
	LinkedList()
	{
		head = NULL;
		tail = NULL;
	}
	void inset(string a, int t, int q)
	{
		Node* newnode = new Node(a, t, q);
		if (!head && !tail)
		{
			head = newnode;
			tail = newnode;
			head->next = head;
			return;
		}
		else
		{
			Node* temp = head;
			while (temp->next != head)
			{
				temp = temp->next;
			}
			temp->next = newnode;
			newnode->next = head;
			tail = newnode;
		}
	}
	void Display()
	{
		if (head != NULL)
		{
			Node* temp = head;
			do
			{
				cout << temp->id << endl;
				temp = temp->next;
			} while (temp != head);
		}
	}
	bool checkloop()
	{
		Node* temp = head;
		do
		{
			if (temp->time >= temp->quota)
				return 1;
			temp = temp->next;
		} while (temp != head);
		return 0;
	}
	void check()
	{
		Node* temp = head;
		do
		{
			if (temp->time >= temp->quota)
			{
				temp->time = temp->time - temp->quota;
				cout << temp->id << endl;
			}
			temp = temp->next;
		} while (checkloop());
	}
};
int main()
{
	int n;
	cin >> n;
	string x;
	int time;
	int quota;
	LinkedList l1;
	while (n)
	{
		cin >> x;
		cin >> time;
		cin >> quota;
		l1.inset(x, time, quota);
		n--;
	}
	l1.check();
}