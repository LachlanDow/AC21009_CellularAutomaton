#include <iostream>
#include "gen.h"
#include "gen2d.h"

using namespace std;

//functions to be added to main.h
int getinput1();
int getinput2();
int create();
int load();
int prmenu(Gen gen);


int main() {
	int menu;
	do {
		cout << "\nCELLULAR AUTOMATON MAIN MENU\n" << flush;
		cout << "1- Create Cellular Automaton\n" << flush;
		cout << "2- Create 2D Cellular Automaton\n" << flush;
		cout << "3- Game of Life\n" << flush;
		cout << "4- Quit\n" << flush;
		cin >> menu;
		cout << "\033[2J\033[1;1H" << flush;

		switch (menu) {
		case 1:
			cout << "CREATE CELLULAR AUTOMATON\n" << flush;
			getinput1();	//runs menus and submenus related to creating automaton 1D or 2D
			break;
		case 2:
			cout << "LOAD SAVED FILE\n" << flush;
			//getinput2();	//create 2D
			break;
		case 3:
			//gameoflife()
			break;
		case 4:
			break;
		default:
			cout << "INVALID CHOICE! RE-Input\n";
		}
	} while (menu != 4);
	return 0;
}

//get inputs for 1D automaton
int getinput1(){
	cout << "\033[2J\033[1;1H" << flush;
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

//	Gen gen;
//	gen.run();		//default vers

	Gen gen2(width, height, seed, rule);
	gen2.run();		//user vers

	return 0;

}


//Get inputs for 2D Automaton
int getinput2(){
	cout << "\033[2J\033[1;1H" << flush;
	int width, height;
	cout << "Enter your desired width: " << flush;
	cin >> width;

	cout << "Enter your desired height: " << flush;
	cin >> height;

	Gen2d gen2d(20,20);
	gen2d.run();

	//Gen2d gen2d(width, height);
	//gen2d.run();
	return 1;
}

