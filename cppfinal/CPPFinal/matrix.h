#pragma once
class Matrix {
private:
	int row;
	int col;
	double* elements;
public:
	Matrix(){ row = 0; col = 0; }
	~Matrix();
	Matrix(int r, int c);
	Matrix(const Matrix& m);
	void setMatrix(const double* values);
	void printMatrix() const;

	int getRow() { return row; }
	int getColumns() { return col; }

	Matrix& getT();
	friend Matrix multiple(Matrix A,Matrix B);
	//Matrix& getInverse();
};