#include<iostream>
using namespace std;
class object {
private:
	int weight;
public:
	object() {
		cout << "构造object对象" << endl;
		weight = 0;
	}
	int getweight() { return weight; }
	void setweight(int weight) { this->weight = weight; }
	~object() { cout << "析构object对象" << endl; }
};
class box :public object {
private:
	int height, width;
public:
	box(){
		cout << "构造box对象" << endl;
		height = width = 0;
	}
	int getheight() { return height; }
	int getwidth() { return width; }
	void setheight(int height) { this->height = height; }
	void setwidth(int width) { this->width = width; }
	~box(){ cout << "析构box对象" << endl; }
};
int main()
{
	box a;
	return 0;
}
