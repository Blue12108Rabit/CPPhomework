#include<iostream>
#include<cmath>
using namespace std;
double cos(double x)
{
	double g = 1;
	double t = -(x*x)/2;
	int n = 1;
	do{
		g += t;
		n++;
		t = -t*(x*x) / ((2*n)*(2*n - 1));
	} while (fabs(t) >= 1e-10);

	return g;
}
double e(double x)
{
	double g=1;
	double t = x;
	int n = 1;
	do{
		g += t;
		n++;
		t = (t*x) / n;
	} while (fabs(t) >= 1e-10);
	return g;
}

int main()
{
	double x;
	cout << "x= " << endl;
	cin >> x;
	double a = cos(x) + e(x);
	cout << "cos(x)= " << cos(x) << ";" << "e(x)= " << e(x) << endl;
	cout << "cos(x)+e(x)=" << a<< endl;
	system("pause");
	return 0;

}