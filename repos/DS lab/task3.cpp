#include<iostream>
using namespace std;
class Node
{
public:
	int id;
	int no;
	Node()
	{
		id = -1;
		no = -1;
	}
	Node(int x,int no):id(x),no(no){}
};
class Hashtable
{
public:
	Node** t;
	Hashtable()
	{
		t = new Node * [10];
		for (int i = 0; i < 10; i++)
		{
			t[i] = new Node[10];
		}
	}
	int hash(int number)
	{
		return number % 10;
	}
	void insert(int id, int no)
	{
		int h = hash(no);
		Node* ptr = t[h];
		int i;
		for (i = 0; i < 10; i++)
		{
			if (ptr[i].id == -1)
			{
				ptr[i].id = id;
				ptr[i].no = no;
				break;
			}
		}
		if (i == 10)
		{
			cout << "Array is full\n";
			return;
		}
	}
	void search(int no)
	{
		int h = hash(no);
		Node* ptr = t[h];
		int i;
		for (i = 0; i < 10; i++)
		{
			if (ptr[i].no == no)
			{
				cout << "ID: " << ptr[i].id<<endl;
				cout << "NO: " << ptr[i].no << endl;
				break;
			}
		}
		if (i == 10)
		{
			cout << "Not found\n";
			return;
		}
	}
	void deleteentry(int n)
	{
		int h = hash(n);
		Node* ptr = t[h];
		int i;
		for (i = 0; i < 10; i++)
		{
			if (ptr[i].no == n)
			{
				ptr[i].id == -1;
				ptr[i].no = -1;
				break;
			}
		}
		if (i == 10)
		{
			cout << "Entry not found";
		}
		return;
	}
	int size()
	{
		int count = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (t[i][j].id != -1)
					count++;
			}
		}
		return count;
	}
	bool isEmpty()
	{
		return !size() ? 1 : 0;
	}
};
int main()
{
	Hashtable obj;
	obj.insert(1, 1);
	obj.insert(2, 2);
	obj.insert(3, 3);
	obj.insert(4, 4);
	obj.insert(5, 12);
	obj.insert(5, 22);
	obj.search(22);
}