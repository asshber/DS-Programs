#include<iostream>
using namespace std;
int i = 0;
struct d
{
	int day;
	int mon;
	int year;
	d()
	{
		i++;
		cout << "Enter Day: ";
		cin >> day;
		cout << "\nEnter Month: ";
		cin >> mon;
		cout << "\nEnter year: ";
		cin >> year;
	}
	d(int x) {};
};
int main()
{
	d date[5];
	int min;
	d temp(5);
	for (int i = 0; i < 4; i++)
	{
		min = i;
		for (int j = i + 1; j < 5; j++)
		{
			if (date[j].year < date[min].year)
				min = j;
			temp = date[min];
			date[min] = date[i];
			date[i] = temp;
		}

	}
	for (int i = 0; i < 5; i++)
	{
		cout << date[i].year<<endl;
	}
	cout << i;
}