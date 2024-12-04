#include <iostream>
using namespace std;

void input() {
	cout << "Enter item's ID: "; cin >> ID;
	cout << "Enter item's name: ";
	char* tmp = new char[50];
	cin.ignore();
	cin.get(tmp, 50);
	name = new char[(strlen(tmp) + 1)];
	strncpy_s(name, strlen(tmp) + 1, tmp, strlen(tmp) + 1);
	delete[] tmp;
	cout << "Enter item's price: "; cin >> price;
}

void display() const {
	cout << "Item's ID : " << ID << endl;
	cout << "Item's name: " << name << endl;
	cout << "Item's price: " << price << endl;
}