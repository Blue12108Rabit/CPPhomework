#include<iostream>
using namespace std;
class Shape
{
public:
	Shape() {}
	~Shape() {}
	virtual float GetArea() = 0;
	virtual float GetPerim() = 0;
};
class Circle : public Shape
{
public:
	Circle(float radius) :itsRadius(radius) {}
	~Circle() {}
	float GetArea() { return 3.14 * itsRadius * itsRadius; }
	float GetPerim() { return 6.28 * itsRadius; }
private:
	float itsRadius;
};
class Rectangle : public Shape
{
public:
	Rectangle(float len, float width): itsLength(len), itsWidth(width) {};
	~Rectangle() {};
	virtual float GetArea() { return itsLength * itsWidth; }
	float GetPerim() { return 2 * itsLength + 2 * itsWidth; }
	virtual float GetLength() { return itsLength; }
	virtual float GetWidth() { return itsWidth; }
private:
	float itsWidth;
	float itsLength;
};
void main()
{
	Shape* sp;
	sp = new Circle(5);
	cout << "The area of the Circle is " << sp->GetArea() << endl;
	cout << "The perimeter of the Circle is " << sp->GetPerim() << endl;
	delete sp;
	sp = new Rectangle(4,6);
	cout << "The area of the Rectangle is " << sp->GetArea() << endl;
	cout << "The perimeter of the Rectangle is " << sp->GetPerim() << endl;
	delete sp;
}
