#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	for (int a = 1; a <= 9; a++)
	{
		for (int b = 1; b <= a; b++)
		{
			cout << b << " * " << a << " = " << a*b << endl;
		}
	}
	system("pause");
	return 0;
}
