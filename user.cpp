#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "ShopManagement.h"

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
	fstream f("buyercart.txt", ios::out, ios::app | ios::binary);
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

void Buyer::modify() {
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


}

