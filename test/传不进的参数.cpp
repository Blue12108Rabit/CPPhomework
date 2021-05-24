#include<iostream>
#include<cmath>
using namespace std;

class point {
public:
	point(double xx, double yy) { x = xx; y = yy; }
	point(point& p) {x = p.x;y = p.y;}
	point() { x = 0; y = 0; }
	void setpoint(double a, double b);
	//void setpoint(double &a, double &b);
	double getx() { return x; }
	double gety() { return y; }

private:
	double x;
	double y;
};
void point::setpoint(double a,double b)
{
	x = a;
	y = b;
}

class circle {
public:
	circle(double a, point c) { r = a; center = c; }
	circle(circle &c);
	circle();
	void setr(double r);
	double getr() { return r; }
	point getp() {return center;}
	point center;
private:
	double r;
};

circle::circle(circle &c)
{
	r = c.r;
	center = c.center;
}
circle::circle()
{
	point aaa(945,250);
	r = 58;
	center = aaa;
}
void circle::setr(double a)
{
	r = a;
}

int isPointInCircle(point& pt, circle& circle)
{
	float l;
	l = sqrt((pt.getx() - circle.getp().getx()) * (pt.getx() - circle.getp().getx()) + (pt.gety() - circle.getp().gety()) * (pt.gety() - circle.getp().gety()));
	if (l < circle.getr())
		return -1;
	else if (l == circle.getr())
		return 0;
	else if (l > circle.getr())
		return 1;
}

int main()
{
	double x1;
	double y1;
	double x2;
	double y2;
	double r;
	point X(9,8);
	cout << X.getx() <<"      "<< X.gety() << endl;
	circle R;
	cout << R.getr() << "      " << R.getp().getx() << "      " << R.getp().gety() << endl;
	cout << "请输入点X坐标: " << endl;
	cout << "x= "; cin >> x1;
	cout << "y= "; cin >> y1;
	X.setpoint(x1, y1);
	cout << X.getx() << "      " << X.gety() << endl;
	cout << "请输入圆心坐标： " << endl;
	cout << "x= "; cin >> x2;
	cout << "y= "; cin >> y2;
	R.getp().setpoint(x2, y2);//为什么传参传不进去？？？？？？？？
	cout << R.getr() << "      " << R.getp().getx() << "      " << R.getp().gety() << endl;
	cout << "请输入圆的半径： " << endl;
	cout << "r= "; cin >> r;
	R.setr(r);
	cout << isPointInCircle(X, R) << endl;
	system("pause");
	return 0;
}