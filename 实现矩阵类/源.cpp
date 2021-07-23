#include "matrix.h"
using namespace std;

int main()
{
	Matrix A = Matrix(3, 3);
	cin >> A;
	Matrix b = Matrix(3, 1);
	cin >> b;
	Matrix x = Matrix::Solve(A, b);
	x.Show();
	return 0;
}