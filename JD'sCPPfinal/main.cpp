#include<iostream>
#include <stdio.h>
#include"matrix.h"
#include"linearequ.h"
using namespace std;
int main() {
	double B[14] = {
		1,19.1,
		1,25,
		1,30.1,
		1,36,
		1,40,
		1,45.1,
		1,50
	};
	double L[7] = { 76.3,77.8,79.25,80.8,82.35,83.9,85.1 };
	LinearEqu l(7, 2);
	l.setLinearEqu(B, L);
	l.printEqu();
	l.solve();
	l.printSolution();
	return 0;
}
