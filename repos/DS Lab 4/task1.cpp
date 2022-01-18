#include<iostream>
#include<string>
using namespace std;
int main()
{
	string arr[5] = { "Flaka","hamdan","Ashber","Ali","Aaamir" };
	string temp;
	for (int i = 0; i < 5-1; i++)
	{
		for (int j = i+1; j < 5; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}
}