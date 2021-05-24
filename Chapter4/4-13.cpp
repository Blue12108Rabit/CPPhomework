#include<iostream>
using namespace std;
const float PI = 3.141593;
class circle
{
public:
	circle(float r);
	circle();
	float getarea();
private:
	float radius;
};
circle::circle(float r)
{
	radius = r;
}
circle::circle()
{
	radius = 0;
}
float circle::getarea()
{
	return radius * radius * PI;
}
int main()
{
	float r1;
	cout << "Please input the radius: ";
	cin >> r1;
	circle round1(r1);
	cout<<"Area = "<<round1.getarea()<<endl;
	return 0;
}

