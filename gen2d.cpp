/*
  Group 19
	Lachlan Dow			170010225
	Afzal Miah			170010026
	Frantisek Pavlica	170020274
*/

#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <cstdlib>
#include <ctime>
#include "gen2d.h"


//constructor with width and height
Gen2d::Gen2d(int width, int height){
	init(width, height);
}

//seed and run
int Gen2d::run() {
	//gliderseed(); //can be used to seed the grid with a glider instead of random values
	//generateAndPrint(50, 150); //can be used to generate and print automatically
	randomize(); //seed the grid with random values
	generateAndPrint(); //run the generation cycle

	return 0;
}

//initialise with width and height, make all values in the grid 0
void Gen2d::init(int width, int height) {
	//set values
	this->width = width;
	this->height = height;

	//set up the grid vectors
	parent.resize(height);
	child.resize(height);

	//set the values at each spot in the vectors to false
	for (int i = 0; i<height; i++) {

		//set up each line vector
		parent.at(i).resize(width);
		child.at(i).resize(width);

		for (int j=0; j<width; j++) {
			//set everever value in the grids to false
			parent.at(i).at(j) = 0;
			child.at(i).at(j) = 0;
		}
	}
}

//put random values into the grid
void Gen2d::randomize(){
	srand(time(0));	//seed rand with time; this is fine as we only care about whether
					//a number is odd or even
	for (int i = 0; i<height; i++) {
		for (int j=0; j<width; j++) {
			parent.at(i).at(j) = (rand()%2); //set each cell to a random bool
		}
	}
}

//set the values at the selected positions to 1 without changing any others
void Gen2d::seed(vector<Position> seed){
	for (auto &pos : seed) {
		//set valus at pos to true
		parent.at(pos.row).at(pos.col) = true;
	}
}

//seeds a glider, only use this if the grid is large enough
void Gen2d::gliderseed(){
	//the cell positions of a glider
	vector<Position> pos(5);
	pos.at(0).row = 0;
	pos.at(0).col = 1;
	pos.at(1).row = 1;
	pos.at(1).col = 2;
	for (int i =2; i < 5; i++) {
		pos.at(i).row = 2;
		pos.at(i).col = i-2;

	}
	seed(pos);
}

//generates 'numOfGens' generations and print them with 'millis' millisecond long breaks;
void Gen2d::generateAndPrint(int numOfGens, int millis){
	for(int i = 0; i < numOfGens; i++) {
		//loop numOfGens times
		printGrid(parent); //print the grid
		nextGen(); //get the next generation
		std::this_thread::sleep_for(std::chrono::milliseconds(millis)); //sleep
		 //https://stackoverflow.com/a/10613664
	}
}

//generates and prints next generations every time an empty newline is inputted
//until any other character is inputted
void Gen2d::generateAndPrint(){
	char c = '\n';
	while(c == '\n') {
		//while the input is only a newline character and nothing else
		printGrid(parent); //print the grid
		nextGen(); //get the next generation
		cout << "Press enter to show the next generation, or input any other character to stop." <<endl;
		c = cin.get(); //get the next character
	}
}

//generates a next generation from parent into child
void Gen2d::nextGen() {

	for (int row = 0; row<height; row++) {
		for (int col=0; col<width; col++) {
			//for each cell
			int num = count(row, col); //count the number of surrounding live cells in parent
			bool newVal;
			if (num <2 || num >3) { 
				newVal = 0; //death by underpopulation or overpopulation
			} else if (num == 3) {
				newVal = 1; //repopulation
			} else { //num ==2, the cell stays the same
				newVal = parent.at(row).at(col);
			}
			child.at(row).at(col) = newVal; //set the value in the grid to the new value
		}
	}

	parent = child;	 //set the parent to the child
}

//same as count but with a different input parameter
int Gen2d::count(Position &pos){
	return count(pos.row, pos.col);
}

//counts the number of 'live' cells of the 8 surrounding cells in parent 
int Gen2d::count(int row, int col){
	int count = 0;

	//add each cell's value to count
	//doing (i-1+width)_width to wrap around;
	count+= parent.at((row-1+width) % width).at((col-1+width) % width); //top left 
	count+= parent.at((row-1+width) % width).at(col); //top center
	count+= parent.at((row-1+width) % width).at((col+1) % width); //top right  

	count+= parent.at(row).at((col-1+width) % width); //middle left 
	count+= parent.at(row).at((col+1) % width); //middle right  

	count+= parent.at((row+1) % width).at((col-1+width) % width); //bottom left 
	count+= parent.at((row+1) % width).at(col); //bottom center
	count+= parent.at((row+1) % width).at((col+1) % width); //bottom right  
	return count;
}

//prints the grid
void Gen2d::printGrid(vector<vector<bool>> grid) {
	clrscr();

	vector<vector<bool>>::iterator colIt;

	for (colIt=grid.begin(); colIt != grid.end(); ++colIt) {
		vector<bool>::iterator rowIt;
		for (rowIt = (*colIt).begin(); rowIt != (*colIt).end(); ++rowIt) {
			//for each cell
			if (*rowIt) {
				cout << "■ " <<flush; //if 1 print a black square
			} else {
				cout << "□ " <<flush; //if 0 print a white square
			}
		}
		cout << "\n"; //go to the next line
	}
	cout <<endl;
}
