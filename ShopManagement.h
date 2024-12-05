#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct Item {
	int ID;
	char* name;
	float price;
};

class Shop {
public:
	void printItem(Item i);
	void displayItems();
	void addItem();
	void removeItem();
	void findItem();
};

class Buyer {
public:
	void addItem();
	void removeItem();
	int bill();
};