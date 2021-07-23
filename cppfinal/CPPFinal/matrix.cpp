#include<iostream>
#include"matrix.h"
#include"linearequ.h"
using namespace std;
Matrix::~Matrix(){
	delete[]elements;
}

Matrix::Matrix(int r, int c) {
	row = r; col = c;
}

Matrix::Matrix(const Matrix& m) {
	


}

void Matrix::setMatrix(const double* values) {
	for (int i = 0; i < row*col; i++){
		elements[i] = values[i];
	}
}


void Matrix::printMatrix()const {
	cout << "The Matrix is: " << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << elements[i,j]<< " ";
		}
		cout << endl;
	}
}
Matrix& Matrix::getT() {
	Matrix cache(col,row);
	double* cache0=new double[row*col];
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cache0[i, j] = elements[j, i];
		}
	}
	cache.setMatrix(cache0);
	return cache;
}
Matrix multiple(Matrix A, Matrix B) {
	Matrix final(A.getRow(), B.getColumns());
	double* cache = new double[A.getRow()*B.getColumns()];
	


}
/*Matrix& Matrix::getInverse() {

}*/
