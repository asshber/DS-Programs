#include<iostream>
using namespace std;
int x;
void fun(int* arr, int size)
{
	if (0 == size)
	{
		for (int i = 0; i < x; i++)
			cout << arr[i] << endl;
		return;
	}
	
	for (int i = 0; i < size-1; i++)
	{
	if (arr[i] > arr[i+1])
	{
		int temp = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = temp;
	}
	}
	fun(arr, size-1);

}
int main()
{
	int arr[] = { 3,2,1,4,8,6,7,0 };
	x = sizeof(arr) / sizeof(int);
	fun(arr,x);
}