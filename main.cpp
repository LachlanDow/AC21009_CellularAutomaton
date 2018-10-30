#include <iostream>
#include "gen.h"

using namespace std;

int main(){
	Gen gen;
	int width, height, seed, rule;
	cout << "Enter your desired width: " << flush;
	cin >> width;

	cout << "Enter your desired height (number of generations): " << flush;
	cin >> height;

	cout << "Where do you want your seed? " << flush;
	cin >> seed;

	cout << "What rule do you want to use? " << flush;
	cin >> rule;

	cout << "width " << width << ", height " << height 
		<< ", seed " << seed << ", rule " << rule << endl;
	cout << "Ignoring those values and using defaults 32, 16, 15, 30." << endl;
	
	gen.run();

	Gen gen2(width, height, seed, rule);
	gen2.run();
	
	return 0;
}