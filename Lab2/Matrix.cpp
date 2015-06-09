#include "Matrix.h"
#include <assert.h>

//default constructor, initialize a 0*0 matrix
Matrix::Matrix()
{
	_cols = 0;
	_rows = 0;
}

//constructor with arguments, initialize a rows*cols matrix with all elements set to 0
Matrix::Matrix(int rows, int cols)
{
	_rows = rows;
	_cols = cols;
	pElems = new int[rows * cols];
	for (int i = 0; i < rows * cols; i++)
	{
		pElems[i] = 0;
	}
}

//free the used memory 
Matrix::~Matrix()
{
	delete[] pElems;
}

//copy constructor, implement a deep copy
Matrix::Matrix(Matrix &mtx)
{
	_rows = mtx._rows;
	_cols = mtx._cols;
	pElems = new int[_rows * _cols];
	for (int i = 0; i < _rows * _cols; i++)
	{
		pElems[i] = mtx.pElems[i];
	}
}
//specify a value for an element
void Matrix::setElem(int row, int col, int value)
{
	assert(row >= 0);
	assert(col >= 0);
	assert(row < _rows);
	assert(row < _cols);
	pElems[row * _cols + col] = value;
}

//accessor, get the number of rows of the matrix
int Matrix::getRows()
{
	return _rows;
}
//accessor, get the number of columns of the matrix
int Matrix::getCols()
{
	return _cols;
}
//accessor, get an element of a specified location from the matrix
int Matrix::getElem(int row, int col)
{
	assert(row >= 0);
	assert(col >= 0);
	assert(row < _rows);
	assert(row < _cols);
	return pElems[row * _cols + col];
}
//add a matrix to the current one
void Matrix::add(Matrix &mtx)
{
	for (int i = 0; i < _rows * _cols; i++)
	{
		pElems[i] += mtx.pElems[i];
	}
}
//subtract a matrix from the current one
void Matrix::subtract(Matrix &mtx)
{
	for (int i = 0; i < _rows * _cols; i++)
	{
		pElems[i] -= mtx.pElems[i];
	}
}
//compare if two matrices are equavalent
bool Matrix::equal(Matrix &mtx)
{
	bool isEqv = false;
	if (_rows == mtx._rows && _cols == mtx._cols)
	{
		for (int i = 0; i < _rows * _cols; i++)
		{
			if (pElems[i] != mtx.pElems[i])
			{
				return isEqv;
			}
		}
		isEqv = true;
		return isEqv;
	}
	else
	{
		return isEqv;
	}
}