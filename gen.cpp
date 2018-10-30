#include <iostream>
//#include <array>
#include "gen.h"
using namespace std;

/*
bool *parent, *child;
int width, height;
int seed; //should be an array of size width
*/
//int width = 32; //temp, ask for width later
//int height = 16; //temp, ask for number of generations later

//ruleBlock rule[ruleSize]; //TODO probably move this to the class too;

//the main() should probably be moved to a different file
int Gen::run() {

	//was gonna have more than a single function in here so we might want to
	//remove this before submitting;
	generateAndPrint();

	return 0;
}

Gen::Gen(){
	setParams(32,16,15,30);
	init();
}

Gen::Gen(int width, int height, int seed, int rule) {
	setParams(width,height, seed, rule);
	init(); //ignoring rule for now
}

void Gen::setParams(int width, int height, int seed, int rule) {
	this->width = width;
	this->height = height;
	this->seed = seed; //should be an array
	cout << "ignoring your choice of rule " << rule << " and using rule 30 instead." <<endl;
}

void Gen::generateAndPrint () {
	for (int i=0; i < height; i++) { //height is the number of generations

		printLine(parent, width);
		nextGen(parent, child); //make a new generation from parent into child

		//copy child into parent
		for (int j = 0; j < width; j++){
			parent[j]=child[j];
		}
	}

}

void Gen::init() {
	parent = new bool[width];
	child = new bool[width];

	//first set values of both lines to false
	for (int i= 0; i <width; i++) {
		parent[i]=false;
		child[i]=false;
	}

	parent[seed]=true; // seed, temp.

	initRule();

	//temp, rule 30 (if ascending, i.e [0] refers to 000, [1] to 001, etc,  [7] to 111)
	//TODO - ask the user for a number, convert it to binary and save each digit here
	bool rule30[ruleSize] = {0,1,1,1,1,0,0,0};
	setRule(rule30);
}

void Gen::nextGen(bool parent[], bool child[]) {

	array<bool, 3> parentIn;

	//first deal with tile at position 0 which has nothing to its left - wrap around to the end
	parentIn = {parent[width-1], parent[0], parent[1]}; 
	for (int i=0; i <ruleSize; i++) {	//try each rule
		if (parentIn == rule[i].input) {	//if a match is found
			child[0]=rule[i].output;	//set the tile in child to the output of the matching rule
		}
	}
	
	//then the last tile - similarly to above
	parentIn = {parent[width-2], parent[width-1], parent[0]};
	for (int i=0; i <ruleSize; i++) {
		if (parentIn == rule[i].input) {
			child[width-1]=rule[i].output;
		}
	}


	//finally deal with the middle
	for (int j=1; j < (width)-1; j++) { //skipping the 0th and last elements 
		parentIn = {parent[j-1], parent[j], parent[j+1]};
		for (int i=0; i <ruleSize; i++) {
			if (parentIn == rule[i].input) {
				child[j]=rule[i].output;
			}
		}
	}

}


//prints a bool array as a line with  "□ " as a false and "■ " as a true
void Gen::printLine(bool line[], int arrayLength) {
	for (int i= 0; i <arrayLength; i++) {
		if (line[i]) {
			cout << "■ ";
		} else {
			cout << "□ ";
		}
	}
	cout <<endl;
}


// hard-code different inputs for each rule,
// so rule[0] has the rule for when the parent cells are {0,0,0}, 
// rule [1] for {0,0,1} etc.
void Gen::initRule(){
	rule[0].input = {0,0,0};
	rule[1].input = {0,0,1};
	rule[2].input = {0,1,0};
	rule[3].input = {0,1,1};
	rule[4].input = {1,0,0};
	rule[5].input = {1,0,1};
	rule[6].input = {1,1,0};
	rule[7].input = {1,1,1};
}

void Gen::setRule(int num) {
	//TODO make sure it is in the acceptable range
	
	//TODO convert decimal number to array of bools, kinda like:
	/*
	Convert con;
	bool rule[rulesize]; //
	con.DecimalToBinary(num, rule); //rule is an array, will be automatically passed
									//as a pointer and will be changed to 1s and 0s

		//or:
	bool rule[ruleSize] = con.DecimalToBinary(num); //if we figure out how to return an array
	*/
	cerr <<"this is not yet supported" <<endl;
}

void Gen::setRule(bool rule[ruleSize]) {
	for (int i = 0; i < ruleSize; i++) {
		this->rule[i].output = rule[i];
	}
}
