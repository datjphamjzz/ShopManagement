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
	fstream f;
public:
	void addItem();
	void removeItem();
};

class Buyer {
	fstream f;
public:
	void addItem();
	void removeItem();
	int bill();
};