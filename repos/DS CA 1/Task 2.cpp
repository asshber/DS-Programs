#include<iostream>
using namespace std;
template <class T,int x>
class DynamicSafeArrays
{
	T* arr;
	int size;
public:
	DynamicSafeArrays()
	{
		arr = new T[x];
		size = x;
		fillarray();
	}
	void fillarray()
	{
		cout << "Enter Values: ";
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}
	}
	DynamicSafeArrays(int a)
	{
		size = a;
		arr = new T[size];
		fillarray();
	}
	T& operator[](int x)
	{
		if (x < 0 || x>(size - 1))
		{
			cout << "You are trying to access a value that is out of range for the array." << endl;
			exit(0);
		}
		return arr[x];
	}
	int getsize()
	{
		return size;
	}
};
template <class T, int x>
void check(DynamicSafeArrays<T,x>a,DynamicSafeArrays<T,x> b)
{
	bool flag = 0;
	for (int i = 0; i < a.getsize(); i++)
	{
		for (int j = 0;j < b.getsize(); j++)
		{
			if (a[i] == b[j])
			{
				flag = 1;
			}
		}
	}
	if (flag == 1)
	{
		cout << "Array is not disjoint";
	}
	else
	{
		cout << "Array is disjoint";
	}
}
int main()
{
	DynamicSafeArrays<int, 4> array;
	DynamicSafeArrays<int, 4> test;
	check(array, test);

}