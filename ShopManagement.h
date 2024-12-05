#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct Item {
	int ID;
	char name[20];
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
	void addItem();
	void removeItem();
	int bill();
};

class Menu {
	Shop s;
	Buyer b;
public:
	void menu();
	Menu(Shop s, Buyer b) {
		this->s = s;
		this->b = b;
	}
};