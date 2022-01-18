#include<iostream>
using namespace std;
class Node
{
public:
	int id;
	int no;
	Node* next;
	Node()
	{
		id = -1;
		no = -1;
		next = NULL;
	}
	Node(int x, int no) :id(x), no(no) 
	{
		next = NULL;
	}
};
class HashTable
{
public:
	Node arr[10];
	int Hash(int n)
	{
		return n % 10;
	}
	void insert(int x,int n)
	{
		int h = Hash(n);
		if (arr[h].id != -1)
		{
			Node* ptr = arr[h].next;
			if (arr[h].next == NULL)
			{
				arr[h].next = new Node(x, n);
				return;
			}
			while (ptr->next!=NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = new Node(x, n);
		}
		else
		{
			arr[h].id = x;
			arr[h].no = n;
		}
	}
	void search(int n)
	{
		int h = Hash(n);
		if (arr[h].no == n)
		{
			cout << "ID: " << arr[h].id<<endl;
			cout << "NO: " << arr[h].no << endl;
		}
		else
		{
			Node* ptr = arr[h].next;
			while (ptr)
			{
				if (ptr->no == n)
				{
					cout << "ID: " << ptr->id << endl;
					cout << "NO: " << ptr->no << endl;
					break;
				}
				ptr = ptr->next;
			}
		}
	}
};
int main()
{
	HashTable obj;
	obj.insert(1, 1);
	obj.insert(2, 2);
	obj.insert(3, 3);
	obj.insert(4, 12);
	obj.insert(4, 22);
	obj.search(22);
}