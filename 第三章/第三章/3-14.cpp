#include<iostream>
#include<cmath>
using namespace std;
double pn(int x,int n)
{
	if (0 == n)
		return 1;
	else if (1 == n)
		return x;
	else
		return ((2 * n - 1)*x*pn(x, n - 1) - (n - 1)*pn(x, n - 2)) / n;
}
int main()
{
	int x;
	int n;
	cout << "x=" << endl;
	cin >> x;
	cout << "n=" << endl;
	cin >> n;
	cout << "P" << n << "(" << x << ")" << "=" << pn(x, n) << endl;
	system("pause");
}