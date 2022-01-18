#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Node
{
public:
	string data;
	Node* next;
	vector<string> arr;
	Node(string x)
	{
		data = x;
		next = NULL;
	}
};
class Linked_List
{

public:
	Node* head;
	Linked_List()
	{
		head = NULL;
	}
	void sort()
	{
		for (auto ptr = head; ptr->next != NULL; ptr = ptr->next)
		{
			for (auto obj = ptr; obj!= NULL; obj = obj->next)
			{
				if (obj->data < ptr->data)
				{
					vector<string> temp;
					string tempdata;
					tempdata = ptr->data;
					ptr->data = obj->data;
					obj->data = tempdata;
					temp = ptr->arr;
					ptr->arr = obj->arr;
					obj->arr = temp;
				}
			}
		}
	}
	vector<string> SameIndex()
	{
		vector<string> ans;
		int min = head->arr.size();
		for (auto ptr = head; ptr!= NULL; ptr = ptr->next)
		{
			if (ptr->arr.size() < min)
				min = ptr->arr.size();
		}
		for (auto ptr = head; ptr!= NULL; ptr = ptr->next)
		{
			if (min == ptr->arr.size())
				ans = ptr->arr;
		}
		return ans;
	}
	void insert(string x)
	{
		if (head == NULL)
		{
			head = new Node(x);
		}
		else
		{
			auto nn = new Node(x);
			auto ptr = head;
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = nn;
		}
	}
	void Display()
	{
		for (auto ptr = head; ptr != NULL; ptr = ptr->next)
		{
			cout << ptr->data << " ";
			for (auto i = 0; i < ptr->arr.size(); i++)
			{
				cout << ptr->arr[i] << " ";
			}
			cout << endl;
		}
	}
};
class BST_Node
{
public:
	string index;
	string data;
	BST_Node* left;
	BST_Node* right;
	BST_Node(string a,string b):index(a),data(b)
	{
		left = right = NULL;
	}
};
class BST
{
public:
	BST_Node* root;
	BST()
	{
		root = NULL;
	}
	BST_Node* insert(BST_Node* x, string index,string data)
	{
		if (x == NULL)
		{
			BST_Node* nn = new BST_Node(index,data);
			x = nn;
			return x;
		}
		else if (data < x->data)
		{
			x->left = insert(x->left, index, data);
		}
		else if (data > x->data)
		{
			x->right = insert(x->right, index, data);
		}
		return x;
	}
	BST_Node* Inorder(BST_Node* a)
	{
		if (a->left != NULL)
		{
			Inorder(a->left);
		}
		cout << a->data << " ";
		if (a->right != NULL)
		{
			Inorder(a->right);
		}
		return a;
	}
	BST_Node* search(BST_Node* a, Node* ptr)
	{
		if (a->data == ptr->data)
		{
			ptr->arr.push_back(a->index);
			return a;
		}
		else
		{
			if (a->left != NULL && a->data > ptr->data)
			{
				return search(a->left, ptr);
			}
			if (a->right != NULL && a->data < ptr->data)
			{
				return search(a->right, ptr);
			}
		}
		return a;
	}
};
int main()
{
	int n;
	cin >> n;
	string x;
	Linked_List sll;
	for (int i = 0; i <= n; i++)
	{
		getline(cin, x);
		sll.insert(x);
	}
	/*cout << endl << endl;
	sll.Display();*/
	vector<BST> tree;
	string index;
	string temp;
	BST temptree;
	while (cin>>index)
	{
		//cin >> index;
		cin.get();
		getline(cin, x);
		for (int i = 0; i < x.length(); i++)
		{
			if (x[i] == ' ')
			{
				temptree.root=temptree.insert(temptree.root, index, temp);
				temp.clear();
			}
			else
			{
				temp.push_back(x[i]);
			}

		}
		temptree.root = temptree.insert(temptree.root, index, temp);
		temp.clear();
		/*cout << endl;
		temptree.Inorder(temptree.root);*/
		tree.push_back(temptree);
		temptree.root = NULL;
	}

	auto ptr = sll.head;
	int flag = 0;
	ptr = ptr->next;
	while (ptr != NULL)
	{
		flag = 0;
		
		for (int i = 0; i < tree.size(); i++)
		{


			for (int x = 0; x < ptr->data.size(); x++)
			{
				if (isspace(ptr->data[x]))
				{
					flag = 1;
					break;
				}
			}

			if (flag == 0)
			{
				tree[i].search(tree[i].root, ptr);
			}
			else
			{
				if (ptr->data == "training example")
				{

				}
				Linked_List templl;
				string temppllinsert;
				for (int i = 0; i < ptr->data.size(); i++)
				{
					if (ptr->data[i] == ' ')
					{
						templl.insert(temppllinsert);
						temppllinsert.clear();
					}
					else
					{
						temppllinsert.push_back(ptr->data[i]);
					}
				}
				templl.insert(temppllinsert);
				temppllinsert.clear();
				for (int i = 0; i < tree.size(); i++)
				{
					for (auto obj = templl.head; obj != NULL; obj = obj->next)
					{
						tree[i].search(tree[i].root, obj);
					}
				}
				
				vector<string> tempv = templl.SameIndex();
					ptr->arr = tempv;
					/*cout << "Hello" << endl;
					templl.Display();*/
					flag = 0;
					templl.head = NULL;
					ptr = ptr->next;
					if (ptr == NULL)
						break;
					if(ptr->next)
					i = -1;
			}
		}
		if (ptr == NULL)
			break;
		ptr = ptr->next;
	}
	sll.sort();
	sll.Display();
}