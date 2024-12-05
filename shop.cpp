#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#include "ShopManagement.h"

void Shop::printItem(Item i) {
	cout << "ID: " << i.ID << endl;
	cout << "Name: " << i.name << endl;
	cout << "Price: " << i.price << endl;
}

void Shop::displayItems() {
	fstream f("database.bin", ios::read | ios::binary);

	if (f.is_open()) {
		Item i;
		while (f.read((char*)&i, sizeof(Item))) {
			printItem(i);
		}
		f.close();
	}
	else cout << "Error when opening file" << endl;
}

void Shop::addItem() {
	fstream f;
	f.open("database.bin", ios::out | ios::binary);
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

void Shop::removeItem() {
	cout << "Enter the ID: ";
	int ID;
	cin >> ID;

	fstream f1("database.bin", ios::in | ios::binary);
	fstream f2("tmp.bin", ios::out | ios::binary);

	if (f1.is_open() && f2.is_open()) {
		Item i;
		bool found = false;

		while (f1.read((char*)&i, sizeof(Item))) {
			if (i.ID != ID) f2.write((char*)&i, sizeof(Item));
			else found = true;
		}

		f1.close();
		f2.close();

		delete("database.bin");
		rename("tmp.bin", "database.bin");

		if (found) cout << "Removed successfully" << endl;
		else cout << "Not found item" << endl;
	}
	else cout << "Error when opening file" << endl;
}

void Shop::findItem() {
	fstream f("database.bin", ios::in | ios::binary);

	if (f.is_open()) {
		Item i;
		while (f.read((char*)&i, sizeof(Item))) {
			if (i.ID == ID) {
				printItem(i);
				return;
			}
		}
		cout << "Not found item" << endl;
		f.close();
	}
	else cout << "Error when opening file" << endl;
}


