#include<iostream>
#include<vector>
using namespace std;
class DynamicSafeArrays
{
	int* arr;
	int size;
	void fillarray()
	{
		cout << "Enter Values: ";
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}
	}
public:
	DynamicSafeArrays() :arr(NULL)
	{
		size = 0;
	}
	
	DynamicSafeArrays(int a)
	{
		size = a;
		arr = new int[size];
		fillarray();
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << endl;
		}
	}
	vector<int> check()
	{
		vector<int> temp;
		temp.push_back(arr[0]);
		for (int i = 0; i < size; i++)
		{
			bool flag = 0;
			for (int j = 0; j < temp.size(); j++)
			{
				if (arr[i] == temp[j])
				{
					flag = 1;
				}
			}
			if (flag == 0)
			{
				temp.push_back(arr[i]);
			}
		}

		return temp;
	}
	int& operator[](int x)
	{
		if (x < 0 || x>(size - 1))
		{
			cout << "You are trying to access a value that is out of range for the array." << endl;
			exit(0);
		}
		return arr[x];
	}
};
int main()
{
	int x;
	cout << "Enter how many values you need in the array";
	cin >> x;
	DynamicSafeArrays arr(x);
	cout << "original array is: " << endl;
	arr.print();
	auto check=arr.check();
	cout << "Array after deleting duplicates is: ";
	for (int i = 0; i < check.size(); i++)
	{
		cout << check[i] << endl;
	}
}