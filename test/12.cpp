#include <iostream>
#include <stdio.h>
using namespace std;
class Matrix {
protected:
	int col;// 矩阵的列数
	int row;//矩阵行数
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
double Matrix::getElement(int x, int y) {
	return elements[col * y + x];

}
Matrix::Matrix(const Matrix& c) {
	this->col = c.col;
	this->row = c.row;
	elements = new double[row * col]();
	//memcpy(this->elements, c.elements, sizeof(double) * row * col);
	memcpy_s(this->elements, sizeof(double) * row * col, c.elements, sizeof(double) * row * col);
}
void Matrix::setElement(int x, int y, double e) {
	if (elements != nullptr)
		elements[col * y + x] = e;
	//cout<<x<<" "<<" "<<y<<" "<<" "<<col<<" " << col * y + x << endl;
}
double* Matrix::getElements() {
	return elements;
}
Matrix::~Matrix() {

	//cout <<" 析构函数被调用"<< col << " " << row << " " << *elements<<endl;

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
	double* bb = new double[(n - 1) * (n - 1)];//创建n-1阶的代数余子式阵bb    
	int mov = 0;//判断行是否移动   
	double sum = 0.0;//sum为行列式的值  
	for (int arow = 0; arow < n; arow++) // a的行数把矩阵a(nn)赋值到b(n-1)  
	{
		for (int brow = 0; brow < n - 1; brow++)//把aa阵第一列各元素的代数余子式存到bb  
		{
			mov = arow > brow ? 0 : 1; //bb中小于arow的行，同行赋值，等于的错过，大于的加一  
			for (int j = 0; j < n - 1; j++)  //从aa的第二列赋值到第n列  
			{
				bb[brow * (n - 1) + j] = aa[(brow + mov) * n + j + 1];
			}
		}
		int flag = (arow % 2 == 0 ? 1 : -1);//因为列数为0，所以行数是偶数时候，代数余子式为1.  
		sum += flag * aa[arow * n] * det(n - 1, bb);//aa第一列各元素与其代数余子式积的和即为行列式
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
	double* bb = new double[(row - 1) * (row - 1)];//创建n-1阶的代数余子式阵bb   
	int pi, pj, q;
	for (int ai = 0; ai < row; ai++) // a的行数把矩阵a(nn)赋值到b(n-1)  
	{
		for (int aj = 0; aj < row; aj++)
		{
			for (int bi = 0; bi < row - 1; bi++)//把元素aa[ai][0]代数余子式存到bb[][]  
			{
				for (int bj = 0; bj < row - 1; bj++)//把元素aa[ai][0]代数余子式存到bb[][]  
				{
					if (ai > bi)    //ai行的代数余子式是：小于ai的行，aa与bb阵，同行赋值  
						pi = 0;
					else
						pi = 1;     //大于等于ai的行，取aa阵的ai+1行赋值给阵bb的bi行  
					if (aj > bj)    //ai行的代数余子式是：小于ai的行，aa与bb阵，同行赋值  
						pj = 0;
					else
						pj = 1;     //大于等于ai的行，取aa阵的ai+1行赋值给阵bb的bi行  

					bb[bi * (row - 1) + bj] = elements[(bi + pi) * row + bj + pj];
				}
			}
			if ((ai + aj) % 2 == 0)  q = 1;//因为列数为0，所以行数是偶数时候，代数余子式为-1.  
			else  q = (-1);
			adjoint[ai * row + aj] = q * det(row - 1, bb);
		}
	}
	for (int i = 0; i < row; i++)//adjoint 转置
	{
		for (int j = 0; j < i; j++)
		{
			double tem = adjoint[i * row + j];
			adjoint[i * row + j] = adjoint[j * row + i];
			adjoint[j * row + i] = tem;
		}
	}

	for (int i = 0; i < row; i++) //逆矩阵  
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
class LinearEqu :public Matrix {
private:
	double* b, * solution;
public:
	LinearEqu();
	LinearEqu(int r, int c);
	~LinearEqu();
	void setLinearEqu(const double* a, const double* b);
	void solve();
	void printEqu();
	void printSolution();
};
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
int main() {
	double H[14] = {
		1,19.1,
		1,25,
		1,30.1,
		1,36,
		1,40,
		1,45.1,
		1,50
	};

	double R[7] = { 76.3,77.8,79.25,80.8,82.35,83.9,85.1 };
	LinearEqu l(7, 2);
	l.setLinearEqu(H, R);
	l.printEqu();
	l.solve();
	l.printSolution();
	return 0;
}
