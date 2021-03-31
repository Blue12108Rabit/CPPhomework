#include<iostream>
#include<cmath>
using namespace std;
int getpower(int x, int y)
{
	if (y < 0)
		return 0;
	else if (1 == y)
		return x;
	else if (0 == y)
		return 1;
	else
		return x*getpower(x, y - 1);
}
double getpower(double x, int y)
{
	if (y < 0)
		return 1 / (getpower(x, -y));
	else if (1 == y)
		return x;
	else if (0 == y)
		return 1;
	else
		return x*getpower(x, y - 1);
}
int main()
{
	int a, m;
	double b;
	cout << "整数a=" << endl;
	cin >> a;
	cout << "实数b=" << endl;
	cin >> b;
	cout << "整数m=" << endl;
	cin >> m;
	cout << "a^m= " << getpower(a, m) << endl;
	cout << "b^m= " << getpower(b, m) << endl;
	system("pause");
}