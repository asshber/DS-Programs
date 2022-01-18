//#include<iostream>
//#include<string>
//using namespace std;
//class Animal
//{
//	string name;
//	string color;
//	int age;
//public:
//	
//	Animal()
//	{
//		cout << "\nEnter the name of the Animal: ";
//		cin >> name;
//	}
//	Animal(int)
//	{}
//	string getname()
//	{
//		return name;
//	}
//	void makesound()
//	{
//		cout << "\nAnimal makes a sound.";
//	}
//};
//
//int main()
//{
//	Animal* ptr = new Animal[5];
//	Animal temp(0);
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = i; j < 5; j++)
//		{
//			if ((ptr + i)->getname() > (ptr + j)->getname())
//			{
//				temp = *(ptr + i);
//				*(ptr + i) = *(ptr + j);
//				*(ptr + j) = temp;
//			}
//		}
//	}
//	cout << "\n\nThe Array after sorting is: \n";
//	for (int i = 0; i < 5; i++)
//	{
//		cout << (ptr+i)->getname() << endl;
//	}
//	delete[] ptr;
//}
#include<iostream>

using namespace std;
int compare(string s1, string s2);
void swap(void* ptr1, void* ptr2);
class Animal {
private:
    string name;
    int legs;
    int wings;
public:
    Animal() {}
    string getname() { return name; }
    Animal(string n, int l, int w) :
        name(n), legs(l), wings(w) {}
    Animal(string n) :
        name(n), legs(0), wings(0) {}

};

int main() {
    string temp;
    int tl;
    int tw;
    Animal* ptr = new Animal[5];
    for (int i = 0; i < 5; i++) {
        cin >> temp;
        ptr[i] = Animal(temp);
    }
    Animal tem;
    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 5; j++) {
            if (compare(ptr[i].getname(), ptr[j].getname()) == 2) {
                swap(ptr[i], ptr[j]);
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << ptr[i].getname() << endl;
    }

    delete[] ptr;
}
int compare(string s1, string s2) {
    bool eval = false;
    int i = 0;
    while (!eval) {
        if (s1[i] > s2[i])
            return 2;
        if (s1[i] < s2[i])
            return 1;
        if (s1[i] == s2[i]) {
            if (s1[i] == '\0' && s2[i] == '\0')
                return 0;
            if (s1[i] == '\0')
                return 2;
            if (s2[i] == '\0')
                return 1;
            i++;
        }


    }
}
void swap(void* ptr1, void* ptr2) {
    void* temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;

}