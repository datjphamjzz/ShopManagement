#include <iostream>
#include <fstream>
#include <string>
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
		
		cout << "Name: ";
		cin.get(i.name, 20, '\n');
		cin.ignore();

		cout << "Price: ";
		cin >> i.price;

		f.write((char*)&i, sizeof(Item));
		f.close();
	}
	else cout << "Error when opening file" << endl;

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
			if (i.ID != ID) {
				f2.write((char*)&i, sizeof(Item));
			}
			else {
				found = true;
			}
		}

		f1.close();
		f2.close();

		if (found) {
			remove("database.txt");
			rename("tmp.txt", "database.txt");
			cout << "Removed successfully" << endl;
		}
		else {
			remove("tmp.txt");
			cout << "Item with ID " << ID << " not found" << endl;
		}
	}
	else {
		cout << "Error when opening file" << endl;
	}
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
				cout << "New ID: ";
				cin >> i.ID;
				cin.ignore();
				cout << "New name: ";
				cin.get(i.name, 20, '\n');
				cin.ignore();
				cout << "New price: ";
				cin >> i.price;

				found = true;
			}
			f2.write((char*)&i, sizeof(Item));
		}

		f1.close();
		f2.close();

		if (found) {
			remove("database.txt");
			rename("tmp.txt", "database.txt");
			cout << "Modified successfully" << endl;
		}
		else {
			remove("tmp.txt");
			cout << "Item with ID " << ID << " not found" << endl;
		}
	}
	else {
		cout << "Error when opening file" << endl;
	}
}




