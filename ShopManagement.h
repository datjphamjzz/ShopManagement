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
	void menu();
	void printItem(Item i);
	void displayItems();
	void addItem();
	void removeItem();
	void findItem();
	void modifyItem();
};

class Buyer {
public:
	void menu();
	void addItem();
	void removeItem();
	int bill();
};

class Menu {
	Shop s;
	Buyer b;
public:
	void menu();
};