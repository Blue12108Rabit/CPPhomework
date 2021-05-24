#include<iostream>
#include<cmath>
#define POINT_OUT_CIRCLE -1
#define POINT_IN_CIRCLE 1
#define POINT_IN_CIRCLE_EDGE 0
using namespace std;

class point {
public:
	point(double xx, double yy);
	point(point& p);
	point();
	void setpoint(double a, double b);
	double getx();
	double gety();

private:
	double x;
	double y;
};
point::point(double xx, double yy) 
{
	x = xx;
	y = yy;
}
point::point(point& p)
{
	this->x = p.x;
	this->y = p.y;
}
point::point()
{
	x = 0;
	y = 0;
}
void point::setpoint(double a, double b)
{
	x = a;
	y = b;
}
double point::getx()
{
	return x;
}
double point::gety()
{
	return y;
}


class circle {
public:
	circle(double r, point center);
	circle();
	void setr(double r);
	double getr();
	point getp();
private:
	double r;
	point center;
};
circle::circle(double a, point b) 
{
	this->center = b;
	this->r = a;
}
circle::circle()
{
	r = 0;
	center.setpoint(0, 0);
}
void circle::setr(double a)
{
	r = a;
}
double circle::getr()
{
	return r;
}
point circle::getp()
{
	return center;
}

int isPointInCircle(point pt, circle circle)
{
	float l = sqrt((pt.getx() - circle.getp().getx()) * (pt.getx() - circle.getp().getx()) + (pt.gety() - circle.getp().gety()) * (pt.gety() - circle.getp().gety()));
	if (l> circle.getr())
		return POINT_OUT_CIRCLE;
	else if (l  == circle.getr())
		return POINT_IN_CIRCLE_EDGE;
	else if (l  < circle.getr())
		return POINT_IN_CIRCLE;
}

int main()
{
	double x1;
	double y1;
	double x2;
	double y2;
	double r;
	point X;
	point x;
	cout << "请输入点X坐标: " << endl;
	cout << "x= "; cin >> x1;
	cout << "y= "; cin >> y1;
	X.setpoint(x1, y1);
	cout << "请输入圆心坐标： " << endl;
	cout << "x= "; cin >> x2;
	cout << "y= "; cin >> y2;
	x.setpoint(x2, y2);
	cout << "请输入圆的半径： " << endl;
	cout << "r= "; cin >> r;
	circle R(r,x);
	cout << isPointInCircle(X, R) << endl;
	//system("pause");
	return 0;
}