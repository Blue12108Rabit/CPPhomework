#pragma once
#include"matrix.h"
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
