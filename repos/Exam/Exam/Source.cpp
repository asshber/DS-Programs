#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
class Investment
{
	string c_name;
	int c_no;
	float c_deposit;
	int c_years;
public:
	Investment(string a, int b, float c, int d) :c_name(a), c_no(b), c_deposit(c), c_years(d)
	{

	};
	void set_name(string x)
	{
		c_name = x;
	}
	void set_no(int x)
	{
		c_no=x;
	}
	void set_deposit(float x)
	{
		c_deposit = x;
	}
	void set_years(int x)
	{
		c_years = x;
	}
	string get_name() {
		return c_name;
	}
	int get_no()
	{
		return c_no;
	}
	float get_deposit()
	{
		return c_deposit;
	}
	int get_years()
	{
		return c_years;
	}
};
class Regular :public Investment
{
public:
	vector<float> comptable;
	Regular(string a, int b, float c, int d) :Investment(a, b, c, d)
	{};
	void generateTable()
	{
		cout << "\nThis will show projected table";
		cout << "\nThe customer name is" << get_name();
		cout << "\nThe customer initial deposit is" << get_deposit();
		cout << "\nThe customer number of years is" << get_years();
		cout << endl << endl;
		comptable.push_back(get_deposit());
		cout << "\tYears\tAmount\tInterest\tEnd Amnt\n";
		for (int i = 0; i < get_years(); i++)
		{
			comptable.push_back(comptable[i] * 1.1f);
			cout << "\t" << i + 1 << "\t" << comptable[i] << "\t" << comptable[i] * 0.1 << "\t" << comptable[i + 1] << "\n";
		}
	}
	void addfile()
	{	
		fstream file;
		file.open("record.txt", ios::app);
		file << get_no() << ' ' << get_name() << ' ' << get_deposit() << ' ' << get_years() << '\n';
		file.close();
		cout << "\nRECORD ADDED";
	}
};
void add()
{
	string name;
	int no;
	float dep;
	int y;
	check1:
	cout << " \nEnter customer Number";
	cin >> no;

	cout << " \nEnter customer Name";
	cin >> name;
	cout << " \nEnter customer Initial Deposit";
	cin >> dep;
	cout << " \nEnter customer Number of years";
	cin >> y;
	Regular obj(name, no, dep, y);
	obj.addfile();
}

void showall()
{
	fstream file;
	file.open("record.txt", ios::in);
	cout << "\n\n\n\t\t\tInvestment Table\n";
	cout << "Customer Number \t Name \t Deposit \t Number Of years";
	cout << endl;
	string name;
	int no;
	float dep;
	int y;
	while (!file.eof())
	{
		file >> no;
		file.get();
		file >> name;
		file.get();
		file >> dep;
		file.get();
		file >> y;
		cout << "\t" << no << "\t" << name << "\t" << dep << "\t" << y << "\n";
	}
}
void table()
{
	int temp;
	cout << "\nEnter the Customer Number:";
	cin >> temp;
	string name;
	int no;
	float dep;
	int y;
	fstream file;
	file.open("record.txt", ios::in);
	while (!file.eof())
	{
		file >> no;
		file.get();
		file >> name;
		file.get();
		file >> dep;
		file.get();
		file >> y;
		if (no == temp)
			break;
	}
	Regular obj(name, no, dep, y);
	obj.generateTable();
}
void edit()
{
	int x;
	cout << "\nEnter the Customer Number:";
	cin >> x;
	string name;
	int no;
	float dep;
	int y;
	fstream file;
	file.open("record.txt", ios::in);
	fstream temp;
	temp.open("temp.txt", ios::out);
	int flag = 0;
	while (!file.eof())
	{
		file >> no;
		file.get();
		file >> name;
		file.get();
		file >> dep;
		file.get();
		file >> y;
		if (no == x)
		{
			flag = 1;
			cout << "\nYou can only edit initial amount\nCustomer name is" << name;
			float amt;
			cout << "\nEnter Amount:";
			cin >> amt;
			temp << no << ' ' << name << ' ' << amt << ' ' << y << '\n';
		}
		else
		{
	temp << no << ' ' << name << ' ' << dep << ' ' << y << '\n';
		}
	}
	if (flag == 0)
	{
		cout << "\nNumber not found";
		cout << ". Retry.";
	}

	temp.close();
	file.close();
	remove("record.txt");
auto a= rename("temp.txt", "record.txt");
}
void del()
{
	cout << "\nEnter the number you want to delete";
	int del;
	cin >> del;
	fstream file;
	file.open("record.txt", ios::in);
	fstream temp;
	temp.open("temp.txt", ios::out);
	string name;
	int no;
	float dep;
	int y;
	int flag = 0;
	while (!file.eof())
	{
		file >> no;
		file.get();
		file >> name;
		file.get();
		file >> dep;
		file.get();
		file >> y;
		if (del == no)
		{
			char xyz;
			cout << "Enter Y to Delete or N to refuse";
			cin >> xyz;
			if (xyz == 'Y')
			{
				flag = 1;
				cout << "\nDelete Successfull";
			}
			else 
				temp << no << ' ' << name << ' ' << dep << ' ' << y << '\n';
		}
		else {
			temp << no << ' ' << name << ' ' << dep << ' ' << y << '\n';
		}
	}
	if (flag == 0)
	{
		cout << "\nNumber not found Retry";
	}
	temp.close();
	file.close();
	remove("record.txt");
	auto a = rename("temp.txt", "record.txt");
}
int main()
{
	cout << "\n\nEnter A to Add,E to edit,D to delete\nV to view Compound interest of table of specific record,\nL to view all data,X to exit";
	char choice;
	cin >> choice;
	switch (choice)
	{
	case 'A':
		add();
		break;
	case 'E':
		edit();
		break;
	case'D':
		del();
		break;
	case'V':
		table();
		break;
	case'L':
		showall();
		break;
	case'X':
		exit(0);
	default:
		main();
	}
	main();
}