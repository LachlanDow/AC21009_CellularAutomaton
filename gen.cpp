#include <iostream>
#include <array>
using namespace std;

const static int width = 32; //temp, ask for width later
const static int height = 16; //temp, ask for number of generations later
const static int ruleSize = 8;


struct ruleBlock {
	//rename this?
	array<bool, 3> input;	// 0, 1, 2 correspond to the square to the left, centre, and right
					// of the child node in the parent

	bool output;	// the result, from the rule
} ;

ruleBlock rule[ruleSize];
bool parent[width], child[width];	//temp ...or not?
									//probable keep global but allocate memory dynamically

void printLine(bool line[], int arrayLength);
void nextGen(bool parent[], bool (&child)[width]);
void generateAndPrint();
void init();


//the main() should probably be moved to a different file
int main() {

	init();
	generateAndPrint();

	return 0;
}

void generateAndPrint () {
	for (int i=0; i < height; i++) { //height is the number of generations

		printLine(parent, width);
		nextGen(parent, child); //make a new generation from parent into child

		//copy child into parent
		for (int j = 0; j < width; j++){
			parent[j]=child[j];
		}
	}

}

void init() {

	//first set values of both lines to false
	for (int i= 0; i <width; i++) {
		parent[i]=false;
		child[i]=false;
	}

	parent[15]=true; // seed, temp.

	//set different inputs for each rule
	rule[0].input = {0,0,0};
	rule[1].input = {0,0,1};
	rule[2].input = {0,1,0};
	rule[3].input = {0,1,1};
	rule[4].input = {1,0,0};
	rule[5].input = {1,0,1};
	rule[6].input = {1,1,0};
	rule[7].input = {1,1,1};

	//temp, rule 30 (if ascending, i.e [0] refers to 000, [1] to 001, etc,  [7] to 111)
	//TODO - ask the user for a number, convert it to binary and save each digit here
	rule[0].output=0;
	rule[1].output=1;
	rule[2].output=1;
	rule[3].output=1;
	rule[4].output=1;
	rule[5].output=0;
	rule[6].output=0;
	rule[7].output=0;
}

void nextGen(bool parent[], bool (&child)[width]) {

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
void printLine(bool line[], int arrayLength) {
	for (int i= 0; i <arrayLength; i++) {
		if (line[i]) {
			cout << "■ ";
		} else {
			cout << "□ ";
		}
		line[i] ?
	}
	cout <<endl;
}