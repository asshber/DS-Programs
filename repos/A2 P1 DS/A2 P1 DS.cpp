#include<iostream>
using namespace std;
class Node
{
public:
	int exponent;
	int coefficeint;
	Node* next;

	Node(int x,int y):coefficeint(x),exponent(y),next(NULL){}
};
class LinkedList
{
	Node* head;
public:
	LinkedList()
	{
		head = NULL;
	}
	void addmember(int x,int y)
	{
		Node* newnode = new Node(x, y);
		if (head == NULL)
		{
			head = newnode;
			return;
		}
		auto temp = head;
		for (; temp->next != NULL; temp = temp->next);
		temp->next = newnode;
	}
	void Display()
	{
		for (auto temp = head; temp != NULL; temp = temp->next)
		{
			cout << temp->coefficeint << " " << "X" << " " << temp->exponent << endl;
		}
	}
	LinkedList& operator+(LinkedList& l1)
	{
		LinkedList res;

		for (auto temp = head; temp != NULL; temp=temp->next)
		{
			int exp = temp->exponent;
			int resi=0;
			for (auto ptr = l1.head; ptr != NULL; ptr = ptr->next)
			{
				if (exp == ptr->exponent)
				{
					resi = temp->coefficeint + ptr->coefficeint;
					res.addmember(resi, ptr->exponent);
					break;
				}
				if (ptr->next == NULL && resi == 0)
				{
					res.addmember(temp->coefficeint, temp->exponent);
				}

			}
		}
		return res;
	}
};
int main()
{
	LinkedList l1;
	int n;
	cin >> n;
	int x;
	int y;
	for (int i = 1; i < 6 && n != 0; i++, n--)
	{
		cin >> x;
		getchar();
		getchar();
		getchar();
		cin >> y;
		l1.addmember(x, y);
	}
	LinkedList l2;
	cin >> n;
	
	for (int i = 1; i < 6 && n != 0; i++, n--)
	{
		cin >> x;
		getchar();
		getchar();
		getchar();
		cin >> y;
		l2.addmember(x, y);
	}
	LinkedList l3 = l1 + l2;
	l3.Display();
}