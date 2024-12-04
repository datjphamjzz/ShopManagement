#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#include "ShopManagement.h"

void Shop::addItem() {
	f.open("database.txt", ios::out | ios::binary);
	if (f.is_open()) {
		Item i;

		cout << "ID: ";
		cin >> i.ID;
		cin.ignore();

		char* tmpName = new char[100];
		cout << "Name: ";
		cin.get(tmpName, 100, '\n');
		cin.ignore();
		i.name = new char[strlen(tmpName) + 1];
		strcpy_s(i.name, strlen(tmpName) + 1, tmpName);
		delete[] tmpName;

		cout << "Price: ";
		cin >> i.price;

		f.write((char*)&i, sizeof(Item));
	}
	else cout << "Error" << endl;

	f.close();
}