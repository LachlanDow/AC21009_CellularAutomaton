#include <array>
#include <vector>

using namespace std;


const static int ruleSize = 8;
const static char filename[] = "output.txt"; //file to save the output to

struct ruleBlock {
	//rename this?
	array<bool, 3> input;	// 0, 1, 2 correspond to the square to the left, centre, and right
					// of the child node in the parent

	bool output;	// the result, from the rule
} ;


class Gen {
private:
	int width, height;
	bool *parent, *child;
	vector<int> seed; 
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
