#include <iostream>
using namespace std;
class BaseClass
{
public:
	virtual void fn1();
	void fn2();
};
void BaseClass::fn1()
{
	cout << "调用基类的虚函数fn1()" << endl;
}
void BaseClass::fn2()
{
	cout << "调用基类的非虚函数fn2()" << endl;
}
class DerivedClass : public BaseClass
{
public:
	void fn1();
	void fn2();
};
void DerivedClass::fn1()
{
	cout << "调用派生类的函数fn1()" << endl;
}
void DerivedClass::fn2()
{
	cout << "调用派生类的函数fn2()" << endl;
}
void main()
{
	DerivedClass aDerivedClass;
	DerivedClass* pDerivedClass = &aDerivedClass;
	BaseClass* pBaseClass = &aDerivedClass;
	pBaseClass->fn1();
	pBaseClass->fn2();
	pDerivedClass->fn1();
	pDerivedClass->fn2();
}
