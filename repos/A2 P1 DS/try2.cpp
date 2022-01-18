#include<iostream>
using namespace std;
class Node
{
public:
	int coefficeint;
	char variable;
	int exp;
	bool addstatus;
	Node* next;
public:
	Node(int c, char v, int e) :coefficeint(c), variable(v), exp(e) { next = NULL; addstatus = 0; }
	Node() :coefficeint(-100), variable(-100), exp(-100) { next = NULL; addstatus = 0; }
};
class Linkedlist
{
	Node* head;
public:
	Linkedlist()
	{
		head = NULL;
	}
	void addattail(Node* ptr)
	{
		auto temp = head;
		for (; temp->next != NULL; temp = temp->next);
		temp->next = ptr;
	}
	void addathead(Node* ptr)
	{
		ptr->next = head;
		head = ptr;
	}
	void insert(int c, char v, int e)
	{
		Node* newnode = new Node(c, v, e);
		if (head == NULL)
		{
			head = newnode;
			return;
		}

		if (newnode->exp > head->exp)
		{
			auto temp = head;
			for (; temp->next != NULL && (newnode->exp >= temp->next->exp); temp = temp->next);
			newnode->next = temp->next;
			temp->next = newnode;
			return;
		}
		else if (newnode->variable > head->variable)
		{
			auto temp = head;
			for (; temp->next != NULL && (newnode->variable >= temp->next->variable); temp = temp->next);
			newnode->next = temp->next;
			temp->next = newnode;
			return;
		}
		else
		{
			addathead(newnode);
		}
	}
	void countnode()
	{
		int count = 0;
		for (auto temp = head; temp != NULL; temp = temp->next, count++);
		cout << count << endl;
	}
	void Display()
	{
		auto temp = head;
		for (; temp != NULL; temp = temp->next)
		{
			cout << temp->coefficeint << " " << temp->variable << " " << temp->exp << endl;
		}
	}
	void add(Linkedlist p, Linkedlist& res)
	{
		auto temp = head;
		bool flag = 0;
		for (; temp != NULL; temp = temp->next)
		{
			for (auto ptr = p.head; ptr != NULL; ptr = ptr->next)
			{
				if (temp->variable == ptr->variable && temp->exp == ptr->exp)
				{
					ptr->addstatus = 1;
					temp->addstatus = 1;
					res.insert(temp->coefficeint + ptr->coefficeint, ptr->variable, ptr->exp);
				}
			}
		}

		for (auto temp = head; temp != NULL; temp = temp->next)
		{
			if (temp->addstatus == 0)
			{
				res.insert(temp->coefficeint, temp->variable, temp->exp);
			}
		}

		for (auto ptr = p.head; ptr != NULL; ptr = ptr->next)
		{
			if (ptr->addstatus == 0)
			{
				res.insert(ptr->coefficeint, ptr->variable, ptr->exp);
			}
		}
	}
	Node* gethead()
	{
		return head;
	}
};
void check(Linkedlist& l1)
{
	for (auto temp = l1.gethead(); temp->next->next != NULL; temp = temp->next)
	{
		if (temp->exp == temp->next->exp && temp->variable == temp->next->variable)
		{
			temp->coefficeint += temp->next->coefficeint;
			temp->next = temp->next->next;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	if (n <= 0)
		exit(0);
	Linkedlist l1;
	int c, e;
	char v;
	for (int i = n; n != 0; n--)
	{
		cin >> c;
		getchar();
		v = getchar();
		getchar();
		cin >> e;
		l1.insert(c, v, e);
	}
	//l1.countnode();
	//l1.Display();

	cin >> n;
	if (n <= 0)
		exit(0);
	Linkedlist l2;
	for (int i = n; n != 0; n--)
	{
		cin >> c;
		//getchar();
		cin >> v;
		//	getchar();
		cin >> e;
		l2.insert(c, v, e);
	}
	//l2.countnode();
	//l2.Display(); 
//	check(l1);
	//check(l2);
	Linkedlist l3;
	l1.add(l2, l3);
	//checkanswer(l3);
	l3.countnode();
	l3.Display();
}