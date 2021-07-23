#include<iostream>
using namespace std;
class baseclass {
private:
public:
	void fn1() { cout << "baseclass fn1!" << endl; }
	void fn2() { cout << "baseclass fn2!" << endl; }
};
class derivedclass :public baseclass {
public:
	void fn1() { cout << "derivedclass fn1!" << endl; }
	void fn2() { cout << "derivedclass fn2!" << endl; }
};
int main()
{
	derivedclass d;
	d.fn1();
	d.fn2();
	derivedclass* p1 = &d;
	p1->fn1();
	p1->fn2();
	baseclass* p2=&d;
	p2->fn1();
	p2->fn2();

}
