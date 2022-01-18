#include <iostream>
#include <string>
#include<vector>
using namespace std;
void check(char** arr, char* string, int size, int i, int j, int posx, int posy, char x, int a, bool flag, bool found);
void checkdown(char** arr, char* string, int size, int i, int j, int posx, int posy, int a, bool found);
bool end1 = 0;
bool comeback = false;
int n, m;
struct ordinate
{
	int x;
	int y;
	char abc;
	ordinate(int a,int b,char c):x(a),y(b),abc(c){}
};
vector<ordinate> result;
void sort()
{
	ordinate temp(0,0,'r');
	/*for (int i = 0; i < result.size()-1; i++)
	{
		if (result[i].x > result[i + 1].x)
		{
			temp = result[i];
			result[i] = result[i + 1];
			result[i + 1] = temp;
		}
	}*/
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i].x << " " << result[i].y << " " << result[i].abc << endl;
	}
}
int main() {
	cin >> n;
	cin >> m;
	if (m != 5)
		m--;
	char** arr;
	arr = new char* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new char[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	int p;
	cin >> p;
	cin.clear();
	fflush(stdin);
	char** match = new char* [p];
	
	int* size = new int[p];
	for (int i = 0; i < p; i++)
	{
		string temp;
		char c = 10000000;
		c = getchar();
		
		if (c != 10)
			temp.push_back(c);
		while (1)
		{
			c = getchar();
			if (c == 32)
				continue;
			if (c == 10)
				break;
			temp.push_back(c);
		}
		size[i] = temp.length();
		match[i] = new char[size[i]];
		for (int j = 0; j < size[i]; j++)
		{
			match[i][j] = temp[j];
		}
		temp.clear();
	}
	int a;
	int b;
	for (int i = 0; i < p; i++)
	{
		check(arr, match[i], size[i], 0, 0, -1, -1, 'a', 0, 0, 0);
		checkdown(arr, match[i], size[i], 0, 0, -1, -1, 0, 0);
		
		end1 = 0;
		comeback = false;
	}
	sort();
	return 0; // always return 0 from here
}

void checkdown(char** arr, char* string, int size, int i, int j, int posx, int posy,int a,bool found)
{
	if ((i==(n-1) && j == m - 1) || a >= size||i>m-1)
	{
		if (posx != -1 && posy != -1)
			result.push_back(ordinate(posx, posy,'D'));
		comeback = true;
		return;
	}
	else
	{
		if (j >= m-1) //wrapp
		{
			j = 0;
			i++;
		}
		if (arr[i][j] == string[0]&&!comeback)
		{
			/*posx = i;
			posy = j;*/
			if(i+1<5)
			checkdown(arr, string, size, i + 1, j, i, j, a+1,1);
			
		}
		else if (arr[i][j] == string[a]||(arr[i][j]=='+'&&found) && !comeback)
		{
			checkdown(arr, string, size, i + 1, j, posx, posy, a + 1, 1);
		}
		else if (arr[i][j] == '*' && found && !comeback)
		{
			if (arr[i + 1][j] == string[size - 1])
			{
				checkdown(arr, string, size, i + 1, j, posx, posy, size, 1);
			}
		}
		else if(found)
		{
			posx = -1;
			posy = -1;
			checkdown(arr, string, size, i, j + 1, posx, posy, size, 0);
		}
	}
	if(!comeback)
	checkdown(arr, string, size, i, j + 1, posx, posy, a, 0);
}
void check(char** arr, char* string, int size, int i, int j, int posx, int posy, char x, int a, bool flag, bool found)
{
	if ((i == n - 1 && j == m - 1)||a>=size)
	{
		if (posx != -1 && posy != -1)
			result.push_back(ordinate(posx, posy,'R'));
		flag = true;
		end1 = true;
		return;
	}
	else
	{
		if (j >= m )
		{
			i++;
			j = 0;
		}
		if ((arr[i][j] == string[a]))
		{
			if (posx == -1 && posy==-1&&x=='a')
			{
				x = 'R';
				posx = i;
				posy = j;
			}
			check(arr, string, size, i, j+1, posx, posy,x,a+1,flag,1);
		}
		if (arr[i][j]=='*'&&(arr[i][j+1]==string[a+1])&&j+1<m)
		{
			if (posx == -1 && posy == -1 && x == 'a')
			{
				x = 'R';
				posx = i;
				posy = j;
			}
			check(arr, string, size, i, j + 2, posx, posy, x, a+2, flag, 1);
		}
		else if (arr[i][j] == '*' && found)
		{
			if (j + 1 >= m)
			{
				end1 = true;
				check(arr, string, size, i, j + 1, posx, posy, x, size, flag, found);
			}
			
			if (arr[i][j + 1] == string[size - 1])
			{
				end1 = true;
				check(arr, string, size, i, j + 1, posx, posy, x, size, flag, found);

			}
			else
			{
				a = 0;
				found = 0;
				check(arr, string, size, i, j + 1, -1, -1, 'a', 0, flag, 0);
			}
			
		}
		else if ((arr[i][j] == '+'&&found))
		{
			//a++;
			check(arr, string, size, i, j + 1, posx, posy, x, a+1, flag, found);
		}
		else if (arr[i][j] == '?' && found)
		{
			a++;
			check(arr, string, size, i, j + 1, posx, posy, x, a, flag, found);
		}
		
		else if (arr[i][j] != string[a] && found)
		{
			check(arr, string, size, i, j + 1, -1, -1, 'a', 0, flag, found);
		}
		else
		{
			if (!flag && found&&a>=size)
			{
				a = 0;
				found = 0;
				check(arr, string, size, i, j + 1, -1, -1, 'a', a, flag, found);
			}
			if (!flag&&!end1)
				check(arr, string, size, i, j + 1, posx, posy, x, a,flag,found);
		}
		
		
		

	}
}

