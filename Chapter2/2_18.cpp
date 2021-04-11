#include<iostream>
using namespace std;
int main()
{
	unsigned int x;
	unsigned int y = 100;
	unsigned int z = 50;
	x = y - z;
	cout << "Different is:" << x << endl;
	x = z - y;
	cout << "\nNow difference is:" << x << endl;
	system("pause");
	return 0;

}