#include<iostream>
using namespace std;
const float PI = 3.141593;
const float FENCE_PRICE = 35;
const float CONCRETE_PRICE = 3.141593;
class circle {
public:
	circle(float r);
	float l();
	float s();
private:
	float radius;
};
circle::circle(float r)
{
	radius = r;
}
float circle::l()
{
	return 2 * PI * radius;
}
float circle::s()
{
	return radius * radius * PI;
}
int main()
{
	float radius;
	cout << "Please input the radius: ";
	cin >> radius;

	circle pool(radius);
	circle poolRim(radius + 3);

	float fenceCost = poolRim.l() * FENCE_PRICE;
	cout << "Fencing cost is " << fenceCost << endl;

	float concreteCost = (poolRim.s() - pool.s()) * CONCRETE_PRICE;
	cout << "Concrete cost is " <<concreteCost<< endl;

	return 0;




}


