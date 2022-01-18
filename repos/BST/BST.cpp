#include<iostream>
#include<vector>
using namespace std;
class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(int b)
	{
		left = right = NULL;
		data = b;
	}
};
class BST
{
public:
	Node* root;
	BST()
	{
		root = NULL;
	}
	Node* insert(Node* ptr, int b)
	{
		if (root == NULL)
		{
			root = new Node(b);
		}
		if (!ptr)
		{
			Node* nn = new Node(b);
			return nn;
		}
		else if (b > ptr->data)
		{
			ptr->right = insert(ptr->right, b);
		}
		else if (b < ptr->data)
		{
			ptr->left = insert(ptr->left, b);
		}
		return ptr;
	}
	void InOrder(Node* ptr,vector<int>& res)
	{
		if (ptr == NULL)
			return;
		InOrder(ptr->left,res);
		res.push_back(ptr->data);
		InOrder(ptr->right, res);
	}
	int min(Node* ptr)
	{
		while (ptr->left != NULL)
		{
			ptr = ptr->left;
		}
		return ptr->data;
	}
	Node* deleten(Node* ptr, int b)
	{
		if (ptr == NULL)
			return NULL;
		if (b > ptr->data)
		{
			ptr->right = deleten(ptr->right, b);
		}
		if (b < ptr->data)
		{
			ptr->left = deleten(ptr->left, b);
		}
		if (b == ptr->data)
		{
			if (!ptr->right && !ptr->left)
			{
				delete ptr;
				return NULL;
			}
			if (!ptr->left && ptr->right)
			{
				Node* temp = ptr;
				ptr = ptr->right;
				delete temp;
				return ptr;
			}
			if (!ptr->right &&ptr->left)
			{
				Node* temp = ptr;
				ptr = ptr->left;
				delete temp;
				return ptr;
			}
			if (ptr->right && ptr->left)
			{
				int temp = min(ptr);
				ptr->data = temp;
				ptr->right=deleten(ptr->right, temp);
				return ptr;
			}
		}
	}
};
int main()
{
	BST obj;
	obj.insert(obj.root, 5);
	obj.insert(obj.root, 6);
	obj.insert(obj.root, 7);
	obj.insert(obj.root, 4);
	obj.insert(obj.root, 3);
	vector<int> res;
	obj.InOrder(obj.root,res);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	res.clear();
	obj.deleten(obj.root, 7);
	obj.InOrder(obj.root, res);
	cout << endl;
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	
	res.clear();
}