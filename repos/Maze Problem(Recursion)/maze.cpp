#include<iostream>
#include<vector>
using namespace std;
#define rows 4
#define col 4
void check(bool arr[4][4], int a, int b);
//THE CODE OF MAZE ONLY IF A SOLUTION IS POSSIBLE.
struct ordinate
{
	int row;
	int cola;
	ordinate(int x, int a) :row(x), cola(a) {}
};
vector<ordinate> res;
int sol[4][4] = { 0 };

int main()
{
	sol[0][0] = 1;
	bool arr[4][4] = { {1,1,1,1},
					   {0,1,0,0},
					   {0,1,1,1,},
					   {0,0,0,1}
	};
	check(arr, rows - 1, col - 1);
	sol[3][3] = 1;
	for (auto i = 0; i < res.size(); i++)
	{
		cout << res[i].row << "," << res[i].cola << endl;
	}
	cout << endl << endl << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
}
void check(bool arr[4][4], int a, int b)
{
	static int i = 0, j = 0;
	int flag1 = -1, flag2 = -1;
	if (i == a && j == b)
	{
		return;
	}
	else
	{
		if (i < rows && j < col)
		{
			if (arr[i][j + 1] == true&&(j+1)<col)
			{
				j++;
				sol[i][j] = true;
				res.push_back(ordinate(i, j));
				check(arr, a, b);
				sol[i][j] = false;
				j--;


				
			}
			if (arr[i + 1][j] == true && (i + 1) < rows)
			{
				i++;
				sol[i][j] = true;
				res.push_back(ordinate(i, j));
				
				check(arr, a, b);
			}
			
		}
		else
		{
			if (j == b)
			{
				i++;
				j = 0;
			}
		}
	}
}