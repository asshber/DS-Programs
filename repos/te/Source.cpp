#include<iostream>
#include<chrono>
#include<sstream>
#pragma warning(disable:4996)
using namespace std;
int main() {
	time_t now = time(0);
	stringstream strs;
	strs << ctime(&now);
	cout << strs.str();
}