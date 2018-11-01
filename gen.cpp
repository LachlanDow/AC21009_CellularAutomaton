#include <iostream>
#include <fstream>
#include "gen.h"
using namespace std;

//run the generator
int Gen::run() {

	//there was going to be more than a single function call here
	generateAndPrint();

	return 0;
}

//unused
Gen::Gen(){
	setParams(32,16,15,32); //set default parameters
	init();
}

//unused
Gen::Gen(int width, int height, int seed, int rule) {
	setParams(width,height, seed, rule); //set the parameters
	init();
}

//constructor, set parameters and initialise
Gen::Gen(int width, int height, vector<int> seed, int rule) {
	setParams(width,height, seed, rule); //set the parameters
	init();
}

//unused
void Gen::setParams(int width, int height, int seed, int rule) {
	vector<int> s(1, seed); //make a vector of size 1 with seed
	setParams(width, height, s, rule); //call setParams with the new vector
}

//set the parameters
void Gen::setParams(int width, int height, vector<int> seed, int rule) {
	this->width = width;
	this->height = height;
	this->seed = seed;
	setRule(rule);
}

//generate 'height' number of generations and print them
void Gen::generateAndPrint () {
	for (int i=0; i < height; i++) { //height is the number of generations

		printLine(parent, width); //print the current generation
		nextGen(parent, child); //make a new generation from parent into child

	}

}

//initialise the parent and child arrays
void Gen::init() {
	parent = new bool[width];
	child = new bool[width];

	//first set values of all cells in each generation to false
	for (int i= 0; i <width; i++) {
		parent[i]=false;
		child[i]=false;
	}

	initRule(); //set up the rule set to know what the three parent cells will look like
	seedca(seed); //seed the parent 
}

//seed the cellular automaton
void Gen::seedca(vector<int> seed) {
	for (unsigned long i = 0; i< seed.size(); i++) {
		parent[seed.at(i) % width] = true; //set the values at seed positions to true; wrapped
	}
}

//get the next generation
void Gen::nextGen(bool parent[], bool child[]) {

	array<bool, 3> parentIn; //set up an array of three bool to save the input cells into

	for (int j=0; j < width; j++) {
		//save the input cells from parent here (top left, top center, top right)
		//(j-1+width) % width to wrap around even with negative values
		parentIn = {parent[(j-1+width) % width], parent[j], parent[(j+1) % width]};
		for (int i=0; i <ruleSize; i++) {
			//try each rule
			if (parentIn == rule[i].input) { //if a match is found (e.g. 011 == 011)
				child[j]=rule[i].output; //set the child cell into what the output of the rule is
			}
		}
	}

	//copy child into parent
	for (int j = 0; j < width; j++){
		parent[j]=child[j];
	}

}


//prints a bool array as a line with  "□ " as a false and "■ " as a true
void Gen::printLine(bool line[], int arrayLength) {
	ofstream fout;
	fout.open(filename, fstream::app); //open the file(see header file) for appending
	for (int i= 0; i <arrayLength; i++) {
		//for each character in a generation
		if (line[i]) {
			cout << "■ " << flush; //if the cell is set to true, output a black square
			fout << "■ ";
		} else {
			cout << "□ " << flush; //if false, a white square
			fout << "□ ";
		}
	}
	cout <<endl; //new line
	fout <<endl; //new line
	fout.close(); //close the file stream
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

//set the rule to rule 'num'
void Gen::setRule(int num) {

	//make sure the rule is within the possible 8-bit range
	while(num <0 || num >255){
		std::cout << "This is not within the valid range for a rule, Please enter again" << '\n';
		std::cin >> num;
	}
 	decimalToBinary(num); //this also sets the rule outputs
 	int thing = binaryToDecimal();
 	cout << thing << endl; //output the number of the rule

}

//convert a binary bool array to a decimal number
int Gen::binaryToDecimal(){
	// declare variable for decimal value
	int decimal = 0;
	for(int i = 0; i < 8;i++){
		//loop to obtain decimal
		decimal = decimal * 2 + rule[7-i].output;
	}
	return decimal;
}

//convert a decimal number to binary and set it as the rule
void Gen::decimalToBinary(int n){
	//set loop index to 0
	int i = 0;
	//loop while there is still numbers to calculate or there isn't an 8 bit binary number filled
	
	while (n > 0 || i < 8){
		//if there is no more number to be divided add 0's to the number
		if(n==0){
			this->rule[i].output= 0;
		}
		//find the output fo the binary number
		this->rule[i].output= n % 2;
		// set the number to the number devided by two
		n =n/2;
		i++;
	}
}

//set the rule to what the  bool array specifies
void Gen::setRule(bool rule[]) {
	for (int i = 0; i < ruleSize; i++) {
		this->rule[i].output = rule[i];
	}
}
