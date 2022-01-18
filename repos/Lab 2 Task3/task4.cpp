#include<iostream>
using namespace std;
int main()
{
	bool arr[5][5] = {
		{0,1,0,1,1},
		{0,0,1,0,1},
		{0,1,0,0,0},
		{1,0,0,0,1},
		{1,1,0,1,0}
	};
	cout << "Enter two indexes of rows for which you want to check: ";
	int x, y;
	cin >> x;
	cin >> y;
	for (int i = 0; i < 5; i++)
	{
		if (arr[x][i] == 1 && arr[y][i] == 1)
		{
			cout << "Row Index " << x << " and row Index " << y << " is both friends on column Index " << i<<endl;
		}
	}
}
