#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Aux
{
	int data;
	int height;
	Aux(int x) :data(x), height(-1) {}
};
struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int x) :data(x)
	{
		left = right = NULL;
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
	Node* insert(Node* x, int key)
	{
		if (root == NULL)
		{
			root = new Node(key);
			return root;
		}
		if (x == NULL)
		{
			x = new Node(key);
		}
		else if (key<x->data)
		{
			x->left = insert(x->left, key);
		}
		else if (key > x->data)
		{
			x->right = insert(x->right, key);
		}
		return x;
	}
	void InOrder(Node* x)
	{
		if (x != NULL)
		{
			InOrder(x->left);
			cout << x->data << " ";
			InOrder(x->right);
		}
	}

};
int levelgetter(Node* x,
	int key, int height)
{
	if (x == NULL)
		return 0;

	if (x->data == key)
		return height;

	int ans = levelgetter(x->left, key, height + 1);
	if (ans != 0)
		return ans;

	ans = levelgetter(x->right, key, height + 1);
	return ans;
}
int main()
{
	vector<Aux> input;
	int n;
	cin >> n;
	BST obj;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		input.push_back(Aux(x));
		obj.insert(obj.root, x);
	}
	int xyz;
	for (int i = 0; i < input.size(); i++)
	{
		input[i].height = levelgetter(obj.root, input[i].data,1);
	}
	int max = -99;
	for (int i = 0; i < input.size(); i++)
	{
		if (max < input[i].height)
		{
			max = input[i].height;
		}
	}
	vector<Aux> temp;
	int min, maxx;
	for (int i = 1; i <= max; i++)
	{
		for (int j = 0; j < input.size(); j++)
		{
			if (i == input[j].height)
			{
				temp.push_back(input[j]);
			}
		}
		min = maxx = temp[0].data;
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i].data > maxx)
				maxx = temp[i].data;
			if (temp[i].data < min)
				min = temp[i].data;
		}
		cout << min <<" "<< maxx << endl;
		temp.clear();
	}
};