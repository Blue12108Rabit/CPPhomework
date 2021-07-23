#include<iostream>
#include"matrix.h"
#include"linearequ.h"
using namespace std;
int main() {
	Matrix m(2,2);
	double a[] = { 1, 2, 4, 4 };
	m.setMatrix(a);

	system("pause");
}