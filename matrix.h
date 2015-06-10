#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <iostream>
using namespace std;

class Matrix
{
	public:
		Matrix(int pRows = 10, int pCols = 10);
		Matrix(string file);
		~Matrix();

		void resize(int pRows, int pCols);
		void print(ostream &sout = cout) const;

		bool loadFile(string file);
		bool saveFile(string file) const;

		int getRows() const;
		int getCols() const;

		void set(int row, int col, int value);
		int get(int row, int col) const;

		const int *operator[](int i) const;
		int *operator[](int i);
	private:
		int **array;
		int rows, cols;
};

#endif

