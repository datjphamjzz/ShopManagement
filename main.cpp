#include <iostream>
#include <fstream>
using namespace std;

#include "ShopManagement.h"

int main() {
	fstream f("database.bin", ios::out | ios::binary);
	Menu m;

	m.menu();

	return 0;
}