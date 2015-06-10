#include <iostream>
#include "matrix.h"
using namespace std;

void doit(Matrix &m)
{
	// print the whole matrix
	m.print();

	// get a specific item in the matrix
	cout << "m[1][2] = " << m[1][2] << endl;

	// get the number of rows/cols in the matrix
	cout << "rows: " << m.getRows() << ", cols: " << m.getCols() << endl;
}

// Main is just for checking input.
// Use "doit" to as your main function instead.
// Main will automatically call "doit" when the input is good.

int main(int argc, char **argv)
{
	Matrix m;
	
	if(argc < 2)
	{
		cout << "Please enter a filename when you call the program!\n";
		return 1;
	}
	
	if(!m.loadFile(argv[1]))
	{
		cout << "Invalid file!\n";
		return 1;
	}
	
	doit(m);
	
	return 0;
}
