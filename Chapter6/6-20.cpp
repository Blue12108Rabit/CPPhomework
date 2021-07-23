#include<iostream>
using namespace std;
class simplecircle {
private:
	int* itsradius=&radius;
	int radius;
public:
	simplecircle(int r) {
		radius = r;
	}
	simplecircle() {
		radius = 0;
	}
	void show() {
		cout << "*itsradius= " << *itsradius<<endl;
		cout << "radius= " << radius << endl;;
	}
};
int main()
{
	simplecircle a(2);
	simplecircle b;
	a.show();
	b.show();
}