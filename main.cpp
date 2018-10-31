#include <iostream>
#include "gen.h"

using namespace std;

//functions to be added to gen.h
int getinput1();
int getinput2();
int create();
int load();
int prmenu(Gen gen);


int main() {
	int menu;
	do {
		cout << "\nCELLULAR AUTOMATON MAIN MENU\n";
		cout << "1- Create Cellular Automaton\n";
		cout << "2- Load Saved File\n";
		cout << "3- Quit\n";
		cin >> menu;

		switch (menu) {
		case 1:
			cout << "CREATE CELLULAR AUTOMATON\n";
			create();	//runs menus and submenus related to creating automaton 1D or 2D
			break;
		case 2:
			cout << "LOAD SAVED FILE\n";
			//load();	Load function not yet implemented
			break;
		case 3:
			break;
		default:
			cout << "INVALID CHOICE! RE-Input\n";
		}
	} while (menu != 3);
	return 0;
}


//sub menu for creating automatons
int create(){
	int menu;
	
	do{
		cout << "\nCREATING CELLULAR AUTOMATON MENU\n";
		cout << "1. 1D Cellular Automaton\n";
		cout << "2. 2D Cellular Automaton\n";
		cout << "3. Quit\n";
		cin >> menu;

		switch (menu){
		case 1:
			getinput1();	//get inputs for 1D and execute relevant sub menus
			break;
		case 2:
			//getinput2();    get inputs for 2D and execute relevant sub menus
			break;
		case 3:
			break;
		default:
			cout << "INVALID INPUT!!! RE-ENTER MENU INPUT: \n";
		}
	}while(menu != 3);
	return 0;
}


//get inputs for 1D automaton
int getinput1(){
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
//	gen.run();
	prmenu(gen);		//default vers

	Gen gen2(width, height, seed, rule);
//	gen2.run();
	prmenu(gen2);		//user vers

	return 0;

}

int prmenu(Gen gen){
	int menu;

	cout << "\nPRINT MENU\n";
	cout << "1. Display Cellular Automaton\n";
	cout << "2. Display as Decimal Value\n";
	cout << "3. Quit\n";
	cin >> menu;
	//gen.run();

	do{
		switch(menu){
			case 1:
				gen.run();
				return 0;
				break;
			case 2:
				//DISPLAY AS DECIMAL FUNCTION TO BE RAN
				break;
			case 3:
				break;
			default:
				cout << "INVALID INPUT!!! RE-ENTER MENU INPUT: ";
		}
	}while(menu != 3);
	return 0;
}
