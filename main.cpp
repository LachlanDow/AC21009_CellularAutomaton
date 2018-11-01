#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include "gen.h"
#include "gen2d.h"

using namespace std;

//functions to be added to main.h
int ca();
int gol();


int main() {
	int menu;
	do {				//do while for menu
		cout << "\nCELLULAR AUTOMATON MAIN MENU\n" << flush;	//display menu options
		cout << "1- Create Cellular Automaton\n" << flush;
		cout << "2- Game of Life\n" << flush;
		cout << "3- Quit\n" << flush;
		cin >> menu;			//get input
		cout << "\033[2J\033[1;1H" << flush;	//clear screen

		switch (menu) {		//switch menu
		case 1:		//create cellular automaton
			cout << "CREATE CELLULAR AUTOMATON\n" << flush;
			ca();	//runs menus and submenus related to creating automaton 1D or 2D
			break;
		case 2:			//game of life
			cout << "GAME OF LIFE\n" << flush;
			gol();	//create 2D
			break;
		case 3:			//quit
			break;
		default:
			cout << "INVALID CHOICE! RE-Input\n" << flush;
		}
	} while (menu != 3);		//termination
	return 0;
}

//1D automaton
int ca(){
	cout << "\033[2J\033[1;1H" << flush;		//clear
	int width, height, rule;			//initialise variables


	
	
	bool valid = false;	//validatation variables
	do{			//runs until correct input
		cout << "Enter your desired width: " << flush;
        cin >> width;
        if (cin.good())
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



	valid = false;			//variable for validation
	do{
	cout << "Enter your desired height(number of generations): " << flush;
        cin >> height;
        if (cin.good())
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


	cout << "Where do you want your seeds (positions separated by spaces)? " << flush; //get input for seeds as line
	string line;
	cin.ignore();
	getline(cin, line);
	int number;
	
	vector<int> seed;
	stringstream iss(line);

	while (iss) {			//separate at spaces for seed options and validate for data type
		if (iss >> number) { //https://stackoverflow.com/a/20659156
			seed.push_back( number );
		} else {
			iss.clear();
			char s;
			iss >> s;
		}
<<<<<<< HEAD
}

=======
	}
>>>>>>> dd5723993041240e9f14edccb4047707d761ca81

    valid = false;			//variable for validation
	do{			//runs until valid
	cout << "What rule do you want to use? " << flush;
        cin >> rule;
        if (cin.good())
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

	Gen gen2(width, height, seed, rule);	//generate automaton
	gen2.run();		//display automaton

	return 0;

}


//Game of life
int gol(){
	cout << "\033[2J\033[1;1H" << flush;	//clear screen
	int width, height;
	cout << "Enter your desired width: " << flush;	//get width input
	cin >> width;

	cout << "Enter your desired height: " << flush; //get height input
	cin >> height;

	Gen2d gen2d(width,height);		//generate game of life
	gen2d.run();			//run game of life
	return 1;
}

