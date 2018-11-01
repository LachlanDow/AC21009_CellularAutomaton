#include <iostream>
#include <string>
#include <sstream>
#include "gen.h"
#include "gen2d.h"

using namespace std;

//functions to be added to main.h
int ca();
int gol();


int main() {
	int menu;
	do {
		cout << "\nCELLULAR AUTOMATON MAIN MENU\n" << flush;
		cout << "1- Create Cellular Automaton\n" << flush;
		cout << "2- Game of Life\n" << flush;
		cout << "3- Quit\n" << flush;
		cin >> menu;
		cout << "\033[2J\033[1;1H" << flush;

		switch (menu) {
		case 1:
			cout << "CREATE CELLULAR AUTOMATON\n" << flush;
			ca();	//runs menus and submenus related to creating automaton 1D or 2D
			break;
		case 2:
			cout << "GAME OF LIFE\n" << flush;
			gol();	//create 2D
			break;
		case 3:
			break;
		default:
			cout << "INVALID CHOICE! RE-Input\n" << flush;
		}
	} while (menu != 3);
	return 0;
}

//1D automaton
int ca(){
	cout << "\033[2J\033[1;1H" << flush;
	int width, height, rule;
	cout << "Enter your desired width: " << flush;



	cin >> width;

	cout << "Enter your desired height(number of generations): " << flush;
	cin >> height;

	cout << "Where do you want your seeds (positions separated by spaces)? " << flush;
	string line;
	cin.ignore();
	getline(cin, line);
	int number;
	vector<int> seed;
	stringstream iss(line);

	while (iss) {
		if (iss >> number) { //https://stackoverflow.com/a/20659156
			seed.push_back( number );
		} else {
			iss.clear();
			char s;
			iss >> s;
			cout << s << " is not a number, skipping it." << endl;
		}
	}

	cout << "What rule do you want to use? " << flush;
	cin >> rule;

	Gen gen2(width, height, seed, rule);
	gen2.run();		//user vers

	return 0;

}


//Game of life
int gol(){
	cout << "\033[2J\033[1;1H" << flush;
	int width, height;
	cout << "Enter your desired width: " << flush;
	cin >> width;

	cout << "Enter your desired height: " << flush;
	cin >> height;

	Gen2d gen2d(width,height);
	gen2d.run();
	return 1;
}

