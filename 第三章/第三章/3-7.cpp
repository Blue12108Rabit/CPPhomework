#include<iostream>
#include<cmath>
using namespace std;
int fun(unsigned short int a, unsigned short int b)
{
	if (0==b)
		return-1;
	else
		return a / b;
}
int main()
{
	unsigned short int a;
	unsigned short int b;
	cin >> a;
	cin >> b;
	cout << fun(a, b) << endl;

	system("pause");
	return 0;
}
