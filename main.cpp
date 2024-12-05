#include <iostream>
#include <fstream>
using namespace std;

#include "ShopManagement.h"

int main() {
	Shop s;
	Buyer b;

	Menu m(s, b);

	m.menu();

	return 0;
}