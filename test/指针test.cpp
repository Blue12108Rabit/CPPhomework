#include<iostream>
using namespace std;
int main()
{
	int i;
	int* p;
	p = &i;
    i = 10;
	
	cout << "&i= " << &i << endl;
	cout << "i= " << i << endl;
	cout << "&p= " << &p << endl;
	cout << "p= " << p << endl;
	cout << "*p= " << *p << endl;

	cout <<endl<< "***" << endl << endl;

	*p = 8;

	cout << "&i= " << &i << endl;
	cout << "i= " << i << endl;
	cout << "&p= " << &p << endl;
	cout << "p= " << p << endl;
	cout << "*p= " << *p << endl;

	int (*p)[3];
	p[1][1] = 0;

}