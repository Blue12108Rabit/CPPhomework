#include<iostream>
#include <stdio.h>
#include"matrix.h"
#include"linearequ.h"
using namespace std;
LinearEqu::LinearEqu() {
	row = 1;
	col = 1;
	b = new double[row]();
	solution = new double[row]();
}
LinearEqu::LinearEqu(int r, int c) :Matrix(r, c) {
	row = r;
	col = c;
	b = new double[row];
	solution = new double[row];
}
LinearEqu::~LinearEqu() {
	delete[]b;
	delete[]solution;
}
void LinearEqu::setLinearEqu(const double* a, const double* b) {
	setMatrix(a);

	memcpy(this->b, b, sizeof(double) * row);

}
void LinearEqu::solve() {
	Matrix A(row, col);
	A.setMatrix(this->elements);
	Matrix B(row, 1);
	B.setMatrix(this->b);
	Matrix AT = A.getT();
	Matrix s = multiple(multiple(A.getT(), A).getInverse(), multiple(A.getT(), B));
	memcpy(solution, s.getElements(), sizeof(double) * row);
}
void LinearEqu::printEqu() {
	cout << "a" << endl;
	for (int i = 0; i < row * col; i++) {
		cout << elements[i] << " ";
		if (i % col == (col - 1))
			cout << endl;
	}
	cout << endl << "b" << endl;
	for (int i = 0; i < row; i++)
		cout << b[i] << endl;
}
void LinearEqu::printSolution() {
	for (int i = 0; i < col; i++)
		cout << solution[i] << endl;

}
