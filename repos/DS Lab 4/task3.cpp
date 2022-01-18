#include<iostream>
using namespace std;
void selectionsort(int* arr, int n);
int main()
{
	int arr[] = { 4,6,2,3,7,8,9,10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	selectionsort(arr, size);
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}
void selectionsort(int* arr, int n)
{
	int i, key, j;
	for (int i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}