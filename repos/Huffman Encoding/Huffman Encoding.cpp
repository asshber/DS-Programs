#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<string>
using namespace std;
struct EncodedInfo
{
	char data;
	string encode;
	EncodedInfo(char a,string x,int y):data(a),encode(x)
	{}
};
struct Node
{
	char data;
	int frequency;
	Node* left;
	Node* right;
	Node(char x):data(x),frequency(1)
	{
		left = NULL;
		right = NULL;
	}
	Node(char x, int y):data(x),frequency(y)
	{
		left = NULL;
		right = NULL;
	}
};
struct checkqueue
{
	bool operator()(Node* x, Node* y)
	{
		return (x->frequency > y->frequency);
	}
};
void buildTree(priority_queue<Node*, vector<Node*>, checkqueue>& x)
{
	Node* left, * right;
	Node* newnode;
	while (x.size() != 1)
	{
		left = x.top();
		x.pop();
		right = x.top();
		x.pop();
		newnode = new Node('/', left->frequency+right->frequency);
		newnode->left = left;
		newnode->right = right;
		x.push(newnode);
	}
}
void huffmancode(Node* x, string y, vector<EncodedInfo>& arr)
{
	if (x == NULL)
		return;
	if (x->data != '/')
	{
		for (int i = 0; i < x->frequency; i++)
			arr.push_back(EncodedInfo(x->data,y, x->frequency));
	}
	huffmancode(x->left, y+"0",arr);
	huffmancode(x->right, y + "1",arr);
}
int main()
{
	fstream file;
	file.open("./input.txt", ios::in);
	char c;
	vector<Node> arr;
	bool flag = 0;
	while (1)
	{
		flag = 0;
		c = file.get();
		if (c == EOF)
			break;
		for (int i=0;i<arr.size();i++)
		{
			if (arr[i].data == c)
			{
				arr[i].frequency++;
				flag = 1;
				break;
			}
		}
		if(!flag)
		{
			arr.push_back(c);
		}
	}
	file.close();
	priority_queue<Node*, vector<Node*>, checkqueue> minHeap;
	for (int i = 0; i < arr.size(); i++)
	{
		minHeap.push(&arr[i]);
	}
	buildTree(minHeap);
	string x = "";
	vector<EncodedInfo> encodedarray;
	huffmancode(minHeap.top(),x,encodedarray);
	//ERASING DUPLICATES in Encoded vector
	for (int i = 0; i < encodedarray.size(); i++)
	{
		for (int j = i+1; j < encodedarray.size(); j++)
		{
			if (encodedarray[i].data == encodedarray[j].data)
			{
				encodedarray.erase(encodedarray.begin()+j);
			}
		}
	}
	//Printint encoded codes
	for (int i = 0; i < encodedarray.size(); i++)
	{
		cout << encodedarray[i].data << " " << encodedarray[i].encode << endl;
	}
	//write ENCODED data to file
	file.open("./input.txt", ios::in);
	fstream fout("./encode.txt", ios::out);
	while (1)
	{
		c = file.get();
		if (c == EOF)
			break;
		for (int i = 0; i < encodedarray.size(); i++)
		{
			if (c == encodedarray[i].data)
			{
				fout << encodedarray[i].encode;
				break;
			}
		}
	}
	file.close();
	fout.close();
	//DECODING
	fout.open("./encode.txt", ios::in);
	string res="";
	while (1)
	{
		c = fout.get();
		if (c == EOF)
			break;
		res.push_back(c);
		for (int i = 0; i < encodedarray.size(); i++)
		{
			if (res == encodedarray[i].encode)
			{
				cout << encodedarray[i].data;
				res.clear();
				break;
			}
		}
	}
	
}
