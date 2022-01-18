#include<iostream>
using namespace std;
int main()
{
	cout << "enter n: ";
	int n;
	cin >> n;
	cout << "\nEntre k: ";
	int k;
	cin >> k;
	int* arr = new int[n];
	int temp;
	for (int i = 0; i < n ; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	int sum = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		if (k - sum < 0)
		{
			cout << count;
			break;
		}
		count++;
	}
}