#include <iostream>

using namespace std;

int main() {
	int sodoku[9][9];
	int sumc[9] = { 0 };
	int sumr[9] = { 0 };
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> sodoku[i][j];
			sumc[i] += sodoku[i][j];
		}
		sodoku[i][8] = 45-sumc[i];
	}
	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			sumr[j] += sodoku[i][j];
		}
		sodoku[8][j] = 45 - sumr[j];
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << sodoku[i][j]<<" ";
		}
		cout << endl;
	}
	return 0; // always return 0 from here
}
