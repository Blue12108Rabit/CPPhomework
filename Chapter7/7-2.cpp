#include<iostream>
using namespace std;
class point {
private:
	int x;
	int y;
protected:
	int a;
public:
	point() { x = 38; y = 89; cout << "p默认构造函数" << endl; }
	point(int x,int y){
		this->x = x;
		this->y = y;
		cout << "p含参构造函数" << endl;
	}
	int getx() { return x; }
	int gety() { return y; }
};

class line :public point {
private:
	int x1;
	int y1;
	point m1;
public:
	line(int x, int y, int a, int d);
	int getx1() { return x1; }	
	int gety1() { return y1; }
	int getxx1() { return m1.getx(); }
	int getyy1() { return m1.gety(); }
};
line::line(int x1,int x2,int x3,int x4) :point(m1),m1(x3,x4){
	this->x1 = x1;
	this->y1 = x2;
	cout << "l含参构造函数" << endl;
}
int main() {
	line l(2, 3, 4, 5);
	cout << l.getx1()<<l.gety1()<<l.getxx1()<<l.getyy1()<<endl;
	cout << l.getx() << l.gety()<<endl;
}