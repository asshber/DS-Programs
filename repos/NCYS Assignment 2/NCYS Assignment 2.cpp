#include <iostream>
using namespace std;
int main()
{
	int input;
	int sum = 0;
	int i;
	for (i = 1; i <= 43; i++)
	{
		cin >> input;
		sum += (input * i);
	}
	//sum = sum / i;
	sum = sum % 256;
	cout << sum;
	cout << endl << endl << endl << endl;
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();

}

