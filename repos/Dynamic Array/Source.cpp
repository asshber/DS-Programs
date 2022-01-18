#include<iostream>
using namespace std;
class Dynamic_Array
{
	int size;
	int* arr;
public:
	Dynamic_Array()
	{
		size = 0;
		arr = new int[size];
	}
	Dynamic_Array(int x)
	{
		size = x;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}
	~Dynamic_Array()
	{
		delete[] arr;
	}
	int returnvalueatpos(int x)
	{

		if (x<1 || x>size)
		{
			cout << "You can't access this position";
			exit(1);
		}
		return *(arr+(x-1));
	}
	void copy(int* test)
	{
		for (int i = 0; i < size; i++)
		{
			test[i] = arr[i];
		}
	}
	void pushback(int x)
	{
		int* temp;
		temp = new int[size + 1];
		size++;
		copy(temp);
		temp[size - 1] = x;
		delete[] arr;
		arr = temp;
	}
	int* begin()
	{
		return arr;
	}
	int* end()
	{
		return &arr[size];
	}
};
int main()
{
	Dynamic_Array test(10);
	test.pushback(55);
	test.pushback(88);
	for(int* i=test.begin();i!=test.end();i++)
	cout << *i <<endl;
}