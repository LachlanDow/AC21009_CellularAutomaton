#include <array>
#include <vector>

using namespace std;



//int width = 32; //temp, ask for width later
//int height = 16; //temp, ask for number of generations later
//const static int ruleSize = 8;
//int width, height;

/*
struct ruleBlock {
	//rename this?
	array<bool, 3> input;	// 0, 1, 2 correspond to the square to the left, centre, and right
					// of the child node in the parent

	bool output;	// the result, from the rule
} ;
*/
//ruleBlock rule[ruleSize];
//bool parent[width], child[width];	//temp ...or not?
									//probable keep global but allocate memory dynamically

//bool *parent, *child;


struct Position{
	int row;
	int col;
};

class Gen2d {
private:
	int width, height, gens;
	//bool *parent, *child;
	//int seed; //should be an array of size width
	//ruleBlock rule[ruleSize];
	vector<vector<bool>> parent, child;

	void init(int width, int height);
	int count(int row, int col);
	int count(Position &pos);
	//void initRule();
public: 
	int run();
	//void printLine(bool line[], int arrayLength);
	void printGrid(vector<vector<bool>>);
	void nextGen();
	void randomize();
	void generateAndPrint(int, int);
	void generateAndPrint();
	void seed(vector<Position> seed);
	void gliderseed();
	//void setRule(int);
	//void setRule(bool ruleSize[]);

	//void setParams(int,int,int,int);

	Gen2d();
	//Gen(int, int, int, int); //third int should be an array
};

