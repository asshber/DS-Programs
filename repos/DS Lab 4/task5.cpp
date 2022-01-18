#include<iostream>
using namespace std;
int main()
{
	int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	int n = sizeof(arr) / sizeof(int);
	int max = arr[0];
	int j;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		else
			j = i;
	}
	int min = arr[n - 1];
	int x;
	for (int i = n-1; i >= 0; i--)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
		else
		{
			x = i;
		}
	}
	cout << "The Sub array that needs sorting is between " << x << " Index and " << j << " Index.";
}
//selection sort is the answer of task 6.