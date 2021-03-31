#include<iostream>
#include<cmath>
using namespace std;
int fun(float f)
{
	float c;
	c = (5*(f - 32)) / 9;
	return c;
}
int main()
{
	float f;
	cout << "input F: " << endl;
	cin >> f;
	cout << "F= " << f << endl;
	cout << "C= "<<fun(f) << endl;

	system("pause");
	return 0;
}
