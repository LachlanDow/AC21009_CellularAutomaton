#include <array>
#include <vector>

using namespace std;



//int width = 32; //temp, ask for width later
//int height = 16; //temp, ask for number of generations later
const static int ruleSize = 8;
const static char filename[] = "output.txt";
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
	vector<int> seed; //should be an array of size width
	ruleBlock rule[ruleSize];

	void init();
	void initRule();
public:
	int run();
	void printLine(bool line[], int arrayLength);
	void nextGen(bool parent[], bool child[]);
	void generateAndPrint();
	void setRule(int);
	void setRule(bool ruleSize[]);
	int binaryToDecimal();
	void decimalToBinary(int);

	void setParams(int,int,int,int);
	void setParams(int, int, vector<int>, int);
	void seedca(vector<int>);

	Gen();
	Gen(int, int, int, int); 
	Gen(int width, int height, vector<int> seed, int rule);
};

/*
class Gen {
public:
	int run();
};
*/
