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

