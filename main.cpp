#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include "gen.h"
#include "gen2d.h"

using namespace std;

//these could have been added to main.h but there's only few of them so
//we deemed doing that unnecessary
int ca();
int gol();
int checkedInput(string, int);
int checkedInput(string);
void clrscr();


int main() {
	int menu;
	do {	//do while for menu
		cout << "\nCELLULAR AUTOMATON MAIN MENU\n" << flush; //display menu options
		cout << "1- Create Cellular Automaton\n" << flush;
		cout << "2- Game of Life\n" << flush;
		cout << "3- Quit\n" << flush;
		cin >> menu; //get input
		clrscr(); //clear screen

		switch (menu) {	
		case 1:
			cout << "CREATE CELLULAR AUTOMATON\n" << flush;
			ca();	//cellular automaton
			break;
		case 2:
			cout << "GAME OF LIFE\n" << flush;
			gol();	//game of life
			break;
		case 3:	//quit
			break;
		default:
			cout << "INVALID CHOICE! RE-Input\n" << flush;
		}
	} while (menu != 3); //termination
	return 0;
}

//1D automaton
int ca(){
	clrscr();
	int width, height, rule;
	
	//get width
	width = checkedInput("Enter your desired width: ", 3); //minimum width is 3

	//get height (number of generations)
	height = checkedInput("Enter your desired height(number of generations): ", 0);

	//the seed is inputted differently than the other values
	cout << "Where do you want your seeds (positions separated by spaces)? " << flush;

	string line;
	cin.ignore(); //clear the cin buffer (leaves a newline at the end otherwise)
	getline(cin, line); //read the whole line
	int number; 
	vector<int> seed; 
	stringstream iss(line); //string stream from the line that was just read

	while (iss) {
		if (iss >> number) { //https://stackoverflow.com/a/20659156
			//if read into the int successfully
			if (number > 0) {
				seed.push_back( number ); //add to the vector if positive
			}
		} else {
			//if can't read into an int, i.e. most likely a character
			iss.clear(); //clear the stream flags (such as fail)
			char s; 
			iss >> s; //save the buffer into a character which is not used 
		}
	}

	//get the rule as a decimal number
	do {
		rule = checkedInput("What rule do you want to use? ", 0);
		//make sure it is within the 8 bit range
		if (rule >255) {
			cout << "The rule must be less than 256; please re-enter." <<endl;
		}
	} while (rule >255);

	Gen gen(width, height, seed, rule); //construct a CA generator
	gen.run();		//run the generator

	return 0; //could be later used to return error codes

}


//Game of life
int gol(){
	clrscr();
	int width, height;

	//get the grid width
    width = checkedInput("Enter your desired width: ",3);

    //get the grid height
	height= checkedInput("Enter your desired height: ", 3);

	cin.ignore();
	Gen2d gen2d(width,height); //construct the game of life generator object
	gen2d.run(); //run it
	return 0;
}

//clear the screen
void clrscr(){
	cout << "\033[2J\033[1;1H" << flush; //the character for clearing the screen
}


int checkedInput(string s, int min){
	int result;
	do {
		result = checkedInput(s); //call checkedInput(string)
		if (result < min) { //if the result is too small, try again
			cout << "This number must not be less than " << min 
				<<"; please re-enter." <<endl;
		}
	} while (result < min);
	return result;
}

int checkedInput(string s) {
	int result;
	bool valid = false;
	do{
	cout << s << flush;
        cin >> result;
        if (cin)
        {
            //everything went well, we'll get out of the loop and return the value
            valid = true;
        }
        else
        {
            //something went wrong, we reset the buffer's state to good
            cin.clear();
            //and empty it
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input; please re-enter." << endl;
        }
    } while (!valid);
    return result;
}

