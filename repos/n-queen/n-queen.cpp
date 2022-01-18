//
//#include <iostream>
//using namespace std;
//bool isSafe(int** arr, int row, int col, int n)
//{
//
//	for (int i = 0; i <n; i++)
//	{
//		if (arr[i][col] == 1)
//			return false;
//	}
//	int x = row;
//	int y = col;
//	while (x >= 0 && y >= 0)
//	{
//		if (arr[x][y] == 1)
//			return false;
//		x--;
//		y--;
//	}
//	x = row;
//	y = col;
//	while (x >= 0 && y < n)
//	{
//		if (arr[x][y] == 1)
//			return false;
//		x--;
//		y++;
//	}
//	return true;
//}
//bool nQueen(int** arr, int x, int n)
//{
//	if (x == n)
//		return true;
//	for (int col = 0; col < n; col++)
//	{
//		if (isSafe(arr, x, col, n))
//		{
//			arr[x][col] = 1;
//
//			if (nQueen(arr, x + 1, n))
//				return true;
//			else
//			{
//				arr[x][col] = 0;
//				continue;
//			}
//		}
//	}
//	return false;
//}
//int main()
//{
//	int** arr;
//	int n;
//	cin >> n;
//	arr = new int* [n];
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = new int[n];
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			arr[i][j] = 0; 
//		}
//		
//	}
//	nQueen(arr, 0, n);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cout << arr[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
#include<iostream>
using namespace std;
bool isSafe(int** arr, int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		if (arr[i][col] == 1)
			return 0;
	}
	int x = row;
	int y = col;
	while (x && y)
	{
		if (arr[x][y] == 1)
			return 0;
		x--;
		y--;
	}
	x = row;
	y = col;
	while (x && y)
	{
		if (arr[x][y] == 1)
			return 0;
		x--;
		y++;
	}
	return 1;
}
bool nQueen(int** arr, int row)
{
	if (row == 4)
		return true;
	for (int col = 0; col < 4; col++)
	{
		if (isSafe(arr, col, row))
		{
			arr[row][col] = 1;
			if (nQueen(arr, row + 1))
			{
				return true;
			}
			{
				arr[row][col] = 0;
				continue;
			}
		}
	}
	return false;
}
int main()
{
	int** arr = new int* [4];
	for (int i = 0; i < 4; i++)
	{
		arr[i] = new int[4];
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr[i][j] = 0;
		}
		cout << endl;
	}
	arr[0][1] = 1;
	for (int i = 1; i < 4; i++)
	{
		nQueen(arr, i);
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}