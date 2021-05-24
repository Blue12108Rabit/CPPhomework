#include<iostream>
using namespace std;
class complex {
public:
	complex(double r,double i):
		real(r),image(i){}
	complex(double r):
		real(r),image(0){}
	void show();
	void add(complex c2) ;
private:
	double real;
	double image;
};
void complex::add(complex c2)
{
	real += c2.real;
	image += c2.image;
}
void complex::show()
{
	cout << real << "+" << image << "i" << endl;
}

int main(){

	complex c1(1.5, 2.5);
	complex c2 = 4.5;
	c1.show();
	c2.show();
	c1.add(c2);
	c1.show();
	return 0;
}

