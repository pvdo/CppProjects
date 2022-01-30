//==============================================
// Name:           Pedro Vitor do Carmo Saraiva Teixeira	
// Student Number: 100036193
// Email:          pvdo-carmo-saraiva-t@myseneca.ca
// Section:        NEF
// Workshop:       2 (DIY)
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include "Gift.h"

using namespace std;
namespace sdds {

	//Function accepts a pointer and print it out
	void gifting(char* description) {
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> description;
	}

	//Function accepts the reference of a float variable, checks the range and print out the value of the reference
	void gifting(double& price) {
		do {
			cout << "Enter gift price: ";
			cin >> price;

			if (price > MAX_PRICE || price < 0) {
				cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
			}

		} while (price > MAX_PRICE || price < 0);
	}

	//Function takes the reference of a integer variable, checks the range, and print the value of the reference
	void gifting(int& units) {
		do {
			cout << "Enter gift units: ";
			cin >> units;
		} while (units < 1 && cout << "Gifts units must be at least 1" << endl);
	}

	void gifting(Gift& gf) {
		cout << "Preparing a gift..." << endl;
		gifting(gf.g_description);
		gifting(gf.g_price);
		gifting(gf.g_units);
		wrap(gf);
	}

	bool wrap(Gift& gf) {
		bool wrapped = false;
		if (gf.wrap_layers != 0) {
			cout << "Gift is already wrapped!" << endl;
			wrapped = false;
		}
		else {
			cout << "Wrapping gifts..." << endl;
			do {
				cout << "Enter the number of wrapping layers for the Gift: ";
				cin >> gf.wrap_layers;
			} while (gf.wrap_layers < 1 && cout << "Layers at minimum must be 1, try again." << endl);

			for (int i = 0; i < gf.wrap_layers; i++) {
				char pattern[MAX_PATTERN + 1];
				cout << "Enter wrapping pattern #" << i + 1 << ": ";
				cin >> pattern;
				
				if (pattern != NULL) {
					int size;
					size = strlen(pattern);
					gf.pattern = new char[size + 1];
					strcpy(gf.pattern, pattern);
					gf.pattern [size] = '\0'; 
					wrapped = true;
				}
				else {
					wrapped = false;
				}
			}
		}
		return wrapped;
	}

	bool unwrap(Gift& gf) {
		int flag;
		if (gf.wrap_layers >= 1) {
			cout << "Gift being unwrapped." << endl;
			delete[] gf.wrap;
			gf.wrap = nullptr;
			gf.wrap_layers = 0;
			flag = 1;
		}
		else {
			cout << "Gift isn't wrapped! Can't unwrap." << endl;
			flag = 0;
		}
		return flag == 1 ? true : false;
	}

	//Function that print out each component of the Struct Gift variable 
	void display(const Gift& gf) {
		cout << "Gift Details:" << endl;
		cout << "Description: " << gf.g_description << endl;
		cout << "Price: " << gf.g_price << endl;
		cout << "Units: " << gf.g_units << endl;
		if (gf.wrap_layers == 0 ) {
			cout << "Unwrapped" << endl;
		}
		else {
			cout << "Wrap Layers: " << gf.wrap_layers << endl;
			for (int i = 0; i < gf.wrap_layers; i++) {
				cout << "Wrap #" << i + 1 << ": " << gf.pattern << endl;
			}
		}

	}
}
