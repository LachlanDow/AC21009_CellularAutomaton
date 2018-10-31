#include <iostream>
#include "gen.h"

using namespace std;

int bsconvertd();
int dconvertbs();
int bsconvertv();
int create();
int load();

int main() {
	int menu;
	do {
		//int menu;
		cout << "CELLULAR AUTOMATON\n";
		cout << "1- Convert Binary String into Decimal\n";
		cout << "2- Convert Decimal into Binary String\n";
		cout << "3- Convert Binary Strings into array of variables\n";
		cout << "4- Create Cellular Automaton\n";
		cout << "5- Load Saved File\n";
		cout << "6- Quit\n";
		cin >> menu;

		switch (menu) {
		case 1:
			cout << "Option 1\n";
			//			bsconvertd();
			break;
		case 2:
			cout << "Option 2\n";
			//			dconvertbs();
			break;
		case 3:
			cout << "Option 3\n";
			//			bsconvertv();
			break;
		case 4:
			cout << "Option 4\n";
						create();
			break;
		case 5:
			cout << "Option 5\n";
			//			load();
			break;
		case 6:
			break;
		default:
			cout << "INVALID CHOICE! RE-Input\n";
		}
	} while (menu != 6);
	return 0;
}


int create(){
	int width, height, seed, rule;
	cout << "Enter your desired width: " << flush;
	cin >> width;

	cout << "Enter your desired height(number of generations): " << flush;
	cin >> height;

	cout << "Where do you want your seed? " << flush;
	cin >> seed;

	cout << "What rule do you want to use? " << flush;
	cin >> rule;

	cout << "width " << width << ", height " << height <<  ", seed " << seed << ", rule " << rule;
	cout << "Ignoring those values and using defaults 32,16,15,39.";

	Gen gen;
	gen.run();

	Gen gen2(width, height, seed, rule);
	gen2.setParams(width, height, seed, rule);
	gen2.run();

	return 0;
}
