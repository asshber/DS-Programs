#include <iostream>
using namespace std;

int main() {
	unsigned int n;
	cin >> n;
	int* arr = new int[n];
	for (auto x = 0; x < n; x++)
		cin >> arr[x];
	int count = 0;
	for (auto xy = 0; xy < n; ++xy)
	{
		for (auto j = xy; j < n; ++j)
		{
			if (arr[xy] > arr[j] && xy < j)
			{
				int a = arr[xy];
				arr[xy] = arr[j];
				arr[j] = a;
				count++;
			}
		}
	}
	cout << count << endl;
	return 0; // always return 0 from here
}
