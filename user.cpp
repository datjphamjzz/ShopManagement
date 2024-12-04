#include <iostream>
#include <fstream>
using namespace std;

#include "ShopManagement.h"

void Buyer::display() {
	f.open("database.txt", ios::in | ios::binary);
	if (!f) {
		cerr << "Error opening file to display!" << endl;
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
	
}



