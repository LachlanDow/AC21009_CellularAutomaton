#include <iostream>
//#include "gen.h"

using namespace std;

int bsconvertd();
int dconvertbs();
int bsconvertv();
int create();
int load();

int main(){
	int menu;
	do{
	//int menu;
	cout<<"CELLULAR AUTOMATON\n";
	cout<<"1- Convert Binary String into Decimal\n";
	cout<<"2- Convert Decimal into Binary String\n";
	cout<<"3- Convert Binary Strings into array of variables\n";
	cout<<"4- Create Cellular Automaton\n";
	cout<<"5- Load Saved File\n";
	cout<<"6- Quit\n";
	cin>>menu;

	switch(menu){
		case 1:
			cout<<"Option 1\n";
//			bsconvertd();
			break;
		case 2:
			cout<<"Option 2\n";
//			dconvertbs();
			break;
		case 3:
			cout<<"Option 3\n";
//			bsconvertv();
			break;
		case 4:
			cout<<"Option 4\n";
//			create();
			break;
		case 5:
			cout<<"Option 5\n";
//			load();
			break;
		case 6:
			break;
		default:
			cout<<"INVALID CHOICE! RE-Input\n";
	}
	}while(menu != 6);
	return 0;
}
