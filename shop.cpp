#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#include "ShopManagement.h"

void Shop::menu() {
	cout << "----------SHOP MENU----------" << endl;
	cout << "1. Display items in shop" << endl;
	cout << "2. Add an item to shop" << endl;
	cout << "3. Find an item" << endl;
	cout << "4. Remove an item from shop" << endl;
	cout << "5. Modify an item" << endl;
	cout << "6. Back to main menu" << endl;
	cout << "Your choice: ";

	int choice;
	cin >> choice;

	switch (choice) {
	case 1:
		displayItems();
		menu();
		break;
	case 2:
		addItem();
		menu();
		break;
	case 3:
		findItem();
		menu();
		break;
	case 4:
		removeItem();
		menu();
		break;
	case 5:
		modifyItem();
		menu();
		break;
	case 6:
		break;
	default:
		cout << "Invalid choice" << endl;
	}
}

void Shop::printItem(Item i) {
	cout << "ID: " << i.ID << endl;
	cout << "Name: " << i.name << endl;
	cout << "Price: " << i.price << endl;
}

void Shop::displayItems() {
	fstream f("database.txt", ios::in | ios::binary);

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
	f.open("database.txt", ios::out | ios:: app |ios::binary);
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

	fstream f1("database.txt", ios::in | ios::binary);
	fstream f2("tmp.txt", ios::out | ios::binary);

	if (f1.is_open() && f2.is_open()) {
		Item i;
		bool found = false;

		while (f1.read((char*)&i, sizeof(Item))) {
			if (i.ID != ID) f2.write((char*)&i, sizeof(Item));
			else found = true;
		}

		f1.close();
		f2.close();

		delete("database.txt");
		rename("tmp.txt", "database.txt");

		if (found) cout << "Removed successfully" << endl;
		else cout << "Not found item" << endl;
	}
	else cout << "Error when opening file" << endl;
}

void Shop::findItem() {
	cout << "ID: ";
	int ID;
	cin >> ID;

	fstream f("database.txt", ios::in | ios::binary);

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

void Shop::modifyItem() {
	cout << "ID: ";
	int ID;
	cin >> ID;

	fstream f1("database.txt", ios::in | ios::binary);
	fstream f2("tmp.txt", ios::out | ios::binary);

	if (f1.is_open() && f2.is_open()) {
		Item i;
		bool found = false;
		while (f1.read((char*)&i, sizeof(Item))) {
			if (i.ID == ID) {
				printItem(i);
				cout << "New ID: " << endl;
				cin >> i.ID;
				cout << "New name: " << endl;
				cin >> i.name;
				cout << "New price: " << endl;
				cin >> i.price;

				f2.write((char*)&i, sizeof(Item));

				cout << "Modified successfully" << endl;
				return;
			}
			else f2.write((char*)&i, sizeof(Item));
		}

		if(!found) cout << "Not found item" << endl;
		f1.close();
		f2.close();
	}
	else cout << "Error when opening file" << endl;
}


