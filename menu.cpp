#include <iostream>
using namespace std;

#include "Shopmanagement.h";

void Menu::menu() {
	cout << "----------MAIN MENU----------" << endl;
	cout << "1. Shop menu";
	cout << "2. Buyer menu";
	cout << "3. Quit";
	cout << "Your choice: ";
	int choice;
	cin >> choice;

	switch (choice) {
	case 1:
		s.menu();
		menu();
		break;
	case 2:
		b.menu();
		menu();
		break;
	case 3:
		break;
	default:
		cout << "Invalid choice" << endl;
	}
}