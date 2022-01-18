#include<iostream>
using namespace std;
class Numbers
{
	int size;
	int* ptr;
public:
	Numbers(int x)
	{
		size = x;
		ptr = new int;
	}
	~Numbers()
	{
		delete ptr;
	}
	int* getptr()
	{
		return ptr;
	}
};
int main()
{
	Numbers obj1(4);
	Numbers obj2 = obj1;
	cout << "Address of ptr in obj1: " << obj1.getptr() << endl;
	cout << "Address of ptr in obj2: " << obj2.getptr() << endl;
//this code will end in a error because when the destructor is called it will try to delete the same memory twice.
}