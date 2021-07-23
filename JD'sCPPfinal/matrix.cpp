#include<iostream>
#include <stdio.h>
#include"matrix.h"
#include"linearequ.h"
using namespace std;
double Matrix::getElement(int x, int y) {
	return elements[col * y + x];
}
Matrix::Matrix(const Matrix& c) {
	this->col = c.col;
	this->row = c.row;
	elements = new double[row * col]();
	memcpy_s(this->elements, sizeof(double) * row * col, c.elements, sizeof(double) * row * col);
}
void Matrix::setElement(int x, int y, double e) {
	if (elements != nullptr)
		elements[col * y + x] = e;
}
double* Matrix::getElements() {
	return elements;
}
Matrix::~Matrix() {
	delete[]elements;
}
Matrix::Matrix() {
	row = 1;
	col = 1;
	elements = new double[row * col];
}
Matrix::Matrix(int r, int c) {
	row = r;
	col = c;
	elements = new double[row * col];
}
void Matrix::setMatrix(const double* values) {
	int d = sizeof(double) * row * col;
	memcpy_s(this->elements, d, values, d);
}
int Matrix::getRow() { return row; }
int Matrix::getColumns() { return col; }
Matrix Matrix::getT() {
	Matrix cache(col, row);
	for (int y = 0; y < row; y++)
		for (int x = 0; x < col; x++)
			cache.setElement(y, x, this->getElement(x, y));
	return cache;
}
Matrix multiple(Matrix A, Matrix B) {
	Matrix cache(A.row, B.col);
	if (A.col != B.row)
		exit(1);
	double result;
	int i;
	for (int y = 0; y < A.row; y++)
		for (int x = 0; x < B.col; x++)
		{
			for (result = 0, i = 0; i < B.row; i++)
			{
				result += A.getElement(i, y) * B.getElement(x, i);
			}
			cache.setElement(x, y, result);
		}
	return cache;
}

double Matrix::det(int n, double* aa)
{
	if (n == 1)
		return aa[0];
	double* bb = new double[(n - 1) * (n - 1)];  
	int mov = 0;
	double sum = 0.0;
	for (int arow = 0; arow < n; arow++)  
	{
		for (int brow = 0; brow < n - 1; brow++)  
		{
			mov = arow > brow ? 0 : 1;   
			for (int j = 0; j < n - 1; j++)  
			{
				bb[brow * (n - 1) + j] = aa[(brow + mov) * n + j + 1];
			}
		}
		int flag = (arow % 2 == 0 ? 1 : -1);
		sum += flag * aa[arow * n] * det(n - 1, bb);
	}
	delete[]bb;
	return sum;
}

Matrix Matrix::getInverse() {
	if (row != col)
		exit(2);
	Matrix cache(row, row);
	double* pC = new double[row * row];
	double det_aa = det(row, elements);
	double* adjoint = new double[row * row];
	double* bb = new double[(row - 1) * (row - 1)];
	int pi, pj, q;
	for (int ai = 0; ai < row; ai++) 
	{
		for (int aj = 0; aj < row; aj++)
		{
			for (int bi = 0; bi < row - 1; bi++)
			{
				for (int bj = 0; bj < row - 1; bj++)
				{
					if (ai > bi)   
						pi = 0;
					else
						pi = 1;   
					if (aj > bj)   
						pj = 0;
					else
						pj = 1;  

					bb[bi * (row - 1) + bj] = elements[(bi + pi) * row + bj + pj];
				}
			}
			if ((ai + aj) % 2 == 0)  q = 1;
			else  q = (-1);
			adjoint[ai * row + aj] = q * det(row - 1, bb);
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < i; j++)
		{
			double tem = adjoint[i * row + j];
			adjoint[i * row + j] = adjoint[j * row + i];
			adjoint[j * row + i] = tem;
		}
	}

	for (int i = 0; i < row; i++) 
	{
		for (int j = 0; j < row; j++)
		{
			pC[i * row + j] = (double)(adjoint[i * row + j] / det_aa);
		}
	}
	delete[]adjoint;
	delete[]bb;
	cache.setMatrix(pC);
	return cache;
}
