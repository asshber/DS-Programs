#include<iostream>
using namespace std;
class HashNode
{
public:
	int data;
	int key;

	
	void set(int d,int k)
	{
		data = d;
		key = k;
	}
};
class HashMapTable
{
	HashNode** arr;
	int n;
public:
	HashMapTable(int n)
	{
		this->n = n;
		arr = new HashNode*[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = new HashNode[n];
		}
	}
	int hashfun(int v)
	{
		return v % n;
	}
	void insert(int v)
	{
		int hash = hashfun(v);
		for (int i = 0; i < n; i++)
		{
			if (arr[hash][i].key != hash)
			{
				arr[hash][i].set(v, hash);
				return;
			}
		}
		cout << "Hash Table is filled.\n";
	}
	int search(int key)
	{
		return arr[key][0].data;
	}
	void Remove(int key)
	{
		arr[key][0].key = -1;
	}
	~HashMapTable()
	{
		for (int i = 0; i < n; i++)
			delete[] arr[i];
		delete[] arr;
	}
	void display()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << arr[i][j].data << " ";
			}
			cout << endl;
		}
	}
	int mid_square_hash(int key)
	{
		int value = key * key;
		int middle_value = middle_value(value);
		return middle_value;
	}
	int Folding_hash(int value1, int value2, int value3)
	{
		return value1 + value2 + value3;
	}
};
int main()
{
	HashMapTable obj(4);
	obj.insert(1);
	obj.insert(2);
	obj.insert(3);
	obj.insert(4);
	obj.insert(11);
	obj.insert(22);
	obj.insert(33);
	obj.insert(44);
	obj.insert(91);
	obj.insert(72);
	obj.insert(63);
	obj.insert(54);
	obj.insert(2);
	obj.insert(5);
	obj.insert(0);
	obj.insert(5);
	obj.display();
}