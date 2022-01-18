#include<iostream>
using namespace std;
int main()
{
	int arr[] = { 5,4,3,2,1 };
	int temp = arr[1];
	arr[1] = arr[4];
	arr[4] = temp;
	for (int i = 0; i < 5; i++)
		cout << arr[i] << endl;
}