#include<iostream>
#define PI 3.14159
using namespace std;
class shape {
public:
	double getarea(){}
};
class rectangle :virtual public shape {
private:
	double length;
	double width;
public:
	rectangle() {
		this->length = 0;
		this->width = 0;
	}
	rectangle(double length, double width) {
		this->length = length;
		this->width = width;
	}
	double getarea() { return length * width; }
};
class circle :virtual public shape {
private:
	double radius;
public:
	circle() {
		this->radius =0;
	}
	circle(double radius) {
		this->radius = radius;
	}
	double getarea() { return PI * radius * radius; }
};
class squre :virtual public rectangle {
private:
	rectangle r1;
public:
	squre(double x);
	double getarea() { return r1.getarea(); }
};
squre::squre(double x) :r1(x,x){
}
int main()
{
	squre s(2);
	cout<<s.getarea()<<endl;
}
