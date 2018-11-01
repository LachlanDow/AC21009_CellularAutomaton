#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <cstdlib>
#include <ctime>
#include "gen2d.h"

//clear the screen
void clearScreen()
{
	cout << "\n\n" << "\033[2J\033[1;1H" << flush;
}

//constructor with width and height
Gen2d::Gen2d(int width, int height){
	init(width, height);
}

//seed and run
int Gen2d::run() {
	//gliderseed();
	//generateAndPrint(gens);
	randomize();
	generateAndPrint();

	return 0;
}

//initialise with width and height, make all values in the grid 0
void Gen2d::init(int width, int height) {

	this->width = width;
	this->height = height;
	gens = 50;
	parent.resize(height);
	child.resize(height);
	//TODO do this in a single for loop
	for (int i = 0; i<height; i++) {
		parent.at(i).resize(width);
		child.at(i).resize(width);
		for (int j=0; j<width; j++) {
			parent.at(i).at(j) = 0;
			child.at(i).at(j) = 0;
		}
	}
}

//put random values into the grid
void Gen2d::randomize(){
	srand(time(0));
	for (int i = 0; i<height; i++) {
		parent.at(i).resize(width);
		child.at(i).resize(width);
		for (int j=0; j<width; j++) {
			parent.at(i).at(j) = (rand()%2);
			child.at(i).at(j) = 0;
		}
	}
}

//set the values at the selected positions to 1 without changing any others
void Gen2d::seed(vector<Position> seed){
	for (auto &pos : seed) {
		//set valus at pos to 1
		parent.at(pos.row).at(pos.col) = 1;
	}
}

//seeds a glider, only use this if the grid is large enough
void Gen2d::gliderseed(){
	vector<Position> pos(5);
	pos.at(0).row = 1;
	pos.at(0).col = 2;
	pos.at(1).row = 2;
	pos.at(1).col = 3;
	for (int i =2; i < 5; i++) {
		pos.at(i).row = 3;
		pos.at(i).col = i-1;

	}
	seed(pos);
}

//generates 'numOfGens' generations and print them with 'millis' millisecond long breaks;
void Gen2d::generateAndPrint(int numOfGens, int millis){
	for(int i = 0; i < numOfGens; i++) {
		printGrid(parent);
		nextGen();
		parent = child;	
		std::this_thread::sleep_for(std::chrono::milliseconds(millis)); //https://stackoverflow.com/a/10613664
	}
}

//generates and prints next generations every time an empty newline is inputted
//until any other character is inputted
void Gen2d::generateAndPrint(){
	char c = '\n';
	while(c == '\n') {
		printGrid(parent);
		nextGen();
		parent = child;	
		cout << "Press enter to show the next generation, or input any other character to stop." <<endl;
		c = cin.get();
		//std::this_thread::sleep_for(std::chrono::milliseconds(150)); //https://stackoverflow.com/a/10613664
	}
}

//generates a next generation from parent into child
void Gen2d::nextGen() {

	for (int row = 0; row<height; row++) {
		for (int col=0; col<width; col++) {
			int num = count(row, col); //count always counts parent
			int newVal;
			if (num <2 || num >3) { 
				newVal = 0; //death by underpopulation or overpopulation
			} else if (num == 3) {
				newVal = 1; //repopulation
			} else { //num ==2, the cell stays the same
				newVal = parent.at(row).at(col);
			}
			child.at(row).at(col) = newVal;
		}
	}
}

//same as count but with a different input parameter
int Gen2d::count(Position &pos){
	return count(pos.row, pos.col);
}

//counts the number of 'live' cells of the 8 surrounding cells in parent 
int Gen2d::count(int row, int col){
	int count = 0;

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
	clearScreen();

	vector<vector<bool>>::iterator colIt;

	for (colIt=grid.begin(); colIt != grid.end(); ++colIt) {
		vector<bool>::iterator rowIt;
		for (rowIt = (*colIt).begin(); rowIt != (*colIt).end(); ++rowIt) {
			if (*rowIt) {
				cout << "😂 " <<flush;
			} else {
				cout << "🌑 " <<flush;
			}
		}
		cout << "\n";
	}
	cout <<endl;
}
