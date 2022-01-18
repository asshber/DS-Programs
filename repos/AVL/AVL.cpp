#include<iostream>
using namespace std;
struct node
{
	node* left;
	node* right;
	int data;
	int dif;
	node()
	{
		left = right = NULL;
		dif = 0;

	}
	node(int a)
	{
		left = right = NULL;
		data = a;
		dif = 0;
	}
};
class AVL
{
public:

	unsigned int count;
	node* root;
public:
	AVL()
	{
		count = 0;
		root = NULL;
	}
	AVL(int a)
	{
		count = 1;
		root = new node(a);
	}
	node* insert(node* temp, int b)
	{
		if (temp == NULL)
		{
			temp = new node(b);
			count++;

			return temp;
		}
		else if (temp->data > b)
		{
			temp->left = insert(temp->left, b);
		}
		else if (temp->data < b)
		{
			temp->right = insert(temp->right, b);
		}
		return temp;

	}
	void balance(int b)
	{
		bool flag = 0;
		getdif(root);
		node* pivot = checkdif(root);
		if (pivot->dif < -1 && b>pivot->right->data)
		{
			node* t = pivot;
			if (root == pivot)
			{
				flag = 1;
			}
			pivot = pivot->right;
			if (flag == 1)
				root = pivot;
			pivot->left = t;
			pivot->right = NULL;
		}
		if (pivot->dif > 1 && b < pivot->left->data)
		{
			node* t = pivot;
			if (root == pivot)
			{
				flag = 1;
			}
			pivot = pivot->left;
			if (flag == 1)
				root = pivot;
			pivot->right = t;
			pivot->left = NULL;
		}
	}
	node* checkdif(node* root)
	{
		if (root->dif < -1 || root->dif > 1)
		{
			return root;
		}
		checkdif(root->left);
		checkdif(root->right);
	}
	int getleftheight(node* temp)
	{
		int count = 0;

		while (temp)
		{
			/*if (temp->left == NULL && temp->right != NULL)
			{
				temp = temp->right;
				count++;
				continue;
			}*/
			/*if (temp->left == NULL && temp->right == NULL)
			{
				return count;
			}*/
			count++;
			temp = temp->left;
		}
		return count;
	}
	int getrightheight(node* temp)
	{
		int count = 0;

		while (temp)
		{
			/*if (temp->right == NULL && temp->left != NULL)
			{
				temp = temp->left;
				count++;
				continue;
			}*/
			/*if (temp->left == NULL && temp->right == NULL)
			{
				return count;
			}*/
			count++;
			temp = temp->right;
		}
		return count;
	}
	void getdif(node* temp)
	{
		if (temp == NULL)
		{
			return;
		}
		if (temp->right == NULL && temp->left == NULL)
		{
			temp->dif = 0;
			return;
		}
		else
		{
			temp->dif = (getleftheight(temp) - getrightheight(temp));
			getdif(temp->left);
			getdif(temp->right);
		}
	}
	node* Inorder(node* a)
	{
		if (a->left != NULL)
		{
			Inorder(a->left);
		}
		cout << a->data << " " << a->dif << endl;;
		if (a->right != NULL)
		{
			Inorder(a->right);
		}
		return a;
	}

};
int main()
{
	AVL obj(5);
	obj.insert(obj.root, 7);
	obj.insert(obj.root, 19);
	obj.insert(obj.root, 12);
	/*obj.insert(obj.root, 16);*/
	obj.getdif(obj.root);
	obj.Inorder(obj.root);
	/*obj.balance(12);
	cout << endl << endl;
	obj.Inorder(obj.root);*/

}