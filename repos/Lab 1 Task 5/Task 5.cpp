#include<iostream>
using namespace std;
void MinMax(int*, int*, int arr[]);
int main()
{
	int min = 0, max = 0;
	int arr[10];
	cout << "Enter 10 values to populate the array:- ";
	for (int i = 0; i < 10; i++)
		cin >> arr[i];
	MinMax(&min, &max,arr);
	cout << "The Minimum value in the array is " << min << endl;
	cout << "The Maximum value in the array is " << max << endl;
}
void MinMax(int* min, int* max,int arr[])
{
	*min = arr[0];
	*max = arr[0];
	for (int i = 0; i < 10; i++)
	{
		if (*min > arr[i])
		{
			*min = arr[i];
		}
		else if (*max < arr[i])
		{
			*max = arr[i];
		}
	}
}