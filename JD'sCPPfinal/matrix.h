#pragma once
class Matrix {
protected:
	int col;
	int row;
	double* elements;
public:
	Matrix();
	Matrix(const Matrix& c);
	Matrix(int r, int c);
	~Matrix();
	void setMatrix(const double* values);
	int getRow();
	int getColumns();
	Matrix getT();
	friend Matrix multiple(Matrix A, Matrix B);
	Matrix getInverse();
	static double det(int n, double* aa);//   求行列式
	double* getElements();
	double getElement(int x, int y);
	void setElement(int x, int y, double e);
};
