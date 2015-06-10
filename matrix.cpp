#include <iostream>
#include <fstream>
#include "matrix.h"
using namespace std;

Matrix::Matrix(int pRows, int pCols)
{
	array = NULL;
	resize(pRows, pCols);
}

Matrix::Matrix(string file)
{
	array = NULL;
	loadFile(file);
}

Matrix::~Matrix()
{
	// Deallocate each row
	for(int i = 0; i < rows; i++)
	{
		delete[] array[i];
	}
	// Deallocate the array of rows
	delete[] array;
}

void Matrix::resize(int pRows, int pCols)
{
	// Deallocate old rows
	if(array != NULL)
	{
		for(int i = 0; i < rows; i++)
		{
			delete[] array[i];
		}
		delete[] array;
		array = NULL;
	}

	// Save new rows
	rows = pRows;
	cols = pCols;
	
	// Allocate an array of rows
	array = new int *[rows];
	for(int i = 0; i < rows; i++)
	{
		// Allocate each row
		array[i] = new int[cols];
		
		// Initialize each row
		for(int j = 0; j < cols; j++)
		{
			array[i][j] = 0;
		}
	}	
}

bool Matrix::loadFile(string file)
{
	ifstream fin;
	fin.open(file);

	int r, c;

	if(!fin.good())
	{
		fin.close();
		return false;
	}
	
	fin >> r >> c;
	if(r > 0 && c > 0)
	{
		resize(r, c);
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
			{
				if(!fin.good())
				{
					fin.close();
					return false;
				}
				fin >> array[i][j];
			}
		}
	}

	fin.close();
	return true;
}

bool Matrix::saveFile(string file) const
{
	ofstream fout;
	fout.open(file);
	
	if(!fout.good())
	{
		fout.close();
		return false;
	}

	fout << rows << " " << cols << "\n";	
	print(fout);
	
	fout.close();
	return true;
}

void Matrix::print(ostream &sout) const
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			sout << array[i][j] << " ";
		}
		sout << "\n";
	}
}

int Matrix::getRows() const
{
	return rows;
}

int Matrix::getCols() const
{
	return cols;
}

// Set a value in the matrix by row and column
void Matrix::set(int row, int col, int value)
{
	array[row][col] = value;
}

// Get a value from the matrix by row and column
int Matrix::get(int row, int col) const
{
	return array[row][col];
}

// Operator for getting
const int *Matrix::operator[](int i) const
{
	return array[i];
}

// Operator for setting
int *Matrix::operator[](int i)
{
	return array[i];
}

// Test the matrix class
/*
int main()
{
	Matrix m(2, 2);

	m[0][0] = 1;
	m[0][1] = 2;
	m[1][0] = 3;
	m[1][1] = 4;

	cout << "Matrix 0, 0: " << m[0][0] << "\n"
	     << "Matrix 0, 1: " << m[0][1] << "\n"
	     << "Matrix 1, 0: " << m[1][0] << "\n"
	     << "Matrix 1, 1: " << m[1][1] << "\n";

	return 0;
}
*/
