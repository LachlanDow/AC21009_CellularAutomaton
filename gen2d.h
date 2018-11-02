/*
  Group 19
	Lachlan Dow			170010225
	Afzal Miah			170010026
	Frantisek Pavlica	170020274
*/

#include <array>
#include <vector>

using namespace std;

void clrscr();

struct Position{
	int row;
	int col;
};

class Gen2d {
private:
	int width, height, gens;
	vector<vector<bool>> parent, child;

	void init(int width, int height);
	int count(int row, int col);
	int count(Position &pos);
public: 
	int run();
	void printGrid(vector<vector<bool>>);
	void nextGen();
	void randomize();
	void generateAndPrint(int, int);
	void generateAndPrint();
	void seed(vector<Position> seed);
	void gliderseed();

	Gen2d(int width, int height);
};

