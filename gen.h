#include <array>

using namespace std;



//int width = 32; //temp, ask for width later
//int height = 16; //temp, ask for number of generations later
const static int ruleSize = 8;
//int width, height;

struct ruleBlock {
	//rename this?
	array<bool, 3> input;	// 0, 1, 2 correspond to the square to the left, centre, and right
					// of the child node in the parent

	bool output;	// the result, from the rule
} ;

//ruleBlock rule[ruleSize];
//bool parent[width], child[width];	//temp ...or not?
									//probable keep global but allocate memory dynamically

//bool *parent, *child;



class Gen {
private:
	int width, height;
	bool *parent, *child;
	int seed; //should be an array of size width
public: 
	int run();
	void printLine(bool line[], int arrayLength);
	void nextGen(bool parent[], bool child[]);
	void generateAndPrint();
	void init();

	Gen();
	Gen(int, int, int, int); //third int should be an array
};

/*
class Gen {
public:
	int run();
};
*/