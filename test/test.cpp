#include<iostream>
using namespace std;
class num {
public:
	int getx() { return x; }
	num* setx() { x = 2; return this; }
private:
	int x = 1;
};
class b {
public:
	num* getnum() { return n; }
private:
	num* n = new num();
};
int main()
{
	b b1;
	cout << b1.getnum().getx() << endl;
	b1.getnum()->setx();//为什么这行代码不起作用？
	cout << b1.getnum().getx() << endl;
	return 0;
}

