#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "ShopManagement.h"

void Buyer::menu() {
	cout << "----------Buyer Menu----------\n";
	cout << "1. Display items\n";
	cout << "2. Add an item\n";
	cout << "3. Remove an item\n";
	cout << "4. Modify an item\n";
	cout << "5. Display cart\n";
	cout << "6. Back to main menu\n";
	cout << "Enter your choice: "; 

	int choice;
	cin >> choice;

	switch (choice) {
	case 1: {
		display();
		menu();
		break;
	}
	case 2: {
		addItem();
		menu();
		break;
	}
	case 3: {
		removeItem();
		menu();
		break;
	}
	case 4: {
		modify();
		menu();
		break;
	}
	case 5: {
		displaycart();
		menu();
		break;
	}
	case 6: {
		break;
	}
	default:
		cout << "Invalid choice!" << endl;
		return;
	}
}

void Buyer::display() {
	fstream f("database.txt", ios::in | ios::binary);
	if (!f) {
		cout << "Error opening file to display!" << endl;
		return;
	}

	Item item;
	while (f.read((char*)(&item), sizeof(item))) {
		cout << "Item ID: " << item.ID << endl;
		cout << "Item Name: " << item.name << endl;
		cout << "Item Price: " << item.price << endl;
	}
	f.close();
}


void Buyer::addItem() {
	fstream f("buyercart.txt", ios::out | ios::app | ios::binary);
	if (!f) {
		cout << "Error opening file to add item!" << endl;
		return;
	}

	cout << "Enter item ID: "; int id;  cin >> id;
	cout << "Enter the number of items: "; int num; cin >> num;
	f.write((char*)(&id), sizeof(id));
	f.write((char*)(&num), sizeof(num));
	f.close();
}

void Buyer::removeItem() {
	fstream f("buyercart.txt", ios::in | ios::binary);
	if (!f) {
		cout << "Error opening file to read item!" << endl;
		return;
	}

	vector<pair<int, int>> items;
	int id, num;
	while (f.read((char*)(&id), sizeof(id))) {
		f.read((char*)(&id), sizeof(id));
		items.push_back(make_pair(id, num));
	}
	f.close();

	cout << "Enter item ID to remove: ";
	int removeID;
	cin >> removeID;

	f.open("buyercart.txt", ios::out | ios::binary);
	if (!f) {
		cout << "Error opening file to remove item!" << endl;
		return;
	}

	for (auto& item : items) {
		if (item.first != removeID) {
			f.write((char*)(&item.first), sizeof(item.first));
			f.write((char*)(&item.second), sizeof(item.second));
		}
	}
	f.close();
}

void Buyer::displaycart() {
	fstream f("buyercart.txt", ios::in | ios::binary);
	if (!f) {
		cout << "Error when opening file to display cart!" << endl;
		return;
	}
	int id, num;
	while (f.read((char*)(&id), sizeof(id))) {
		f.read((char*)(&num), sizeof(num));
		cout << "Item's ID: " << id << endl;
		cout << "Number of items: " << num << endl;
	}
}

void Buyer:: modify() {
	fstream f("buyercart.txt", ios::in, ios::binary);
	if (!f) {
		cout << "Error opening file to read item!" << endl;
		return;
	}

	vector<pair<int, int>> items;
	int id, num;
	while (f.read((char*)(&id), sizeof(id))) {
		f.read((char*)(&id), sizeof(id));
		items.push_back(make_pair(id, num));
	}
	f.close();

	cout << "Enter item ID to modify: ";
	int modifyID;
	cin >> modifyID;

	bool found = false;
	for (auto& item : items) {
		if (item.first == modifyID) {
			cout << "Enter new number of items: ";
			cin >> item.second;
			found = true;
			break;
		}
	}

	if (!found) {
		cout << "Item ID not found!" << endl;
		return;
	}

	f.open("buyercart.txt", ios::out | ios::binary);
	if (!f) {
		cout << "Error opening file to write items!" << endl;
		return;
	}

	for (const auto& item : items) {
		f.write((char*)(&item.first), sizeof(item.first));
		f.write((char*)(&item.second), sizeof(item.second));
	}
	f.close();
}

