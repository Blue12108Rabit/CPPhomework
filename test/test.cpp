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
	b1.getnum()->setx();//Ϊʲô���д��벻�����ã�
	cout << b1.getnum().getx() << endl;
	return 0;
}

