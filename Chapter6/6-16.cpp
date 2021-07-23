#include<iostream>
using namespace std;
int main()
{
	int a;
	int* p = &a;
	*p = 10;
	int& r = a;
	r = 5;
}