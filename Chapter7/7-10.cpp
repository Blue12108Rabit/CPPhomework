#include<iostream>
using namespace std;
class object {
private:
	int weight;
public:
	object() {
		cout << "����object����" << endl;
		weight = 0;
	}
	int getweight() { return weight; }
	void setweight(int weight) { this->weight = weight; }
	~object() { cout << "����object����" << endl; }
};
class box :public object {
private:
	int height, width;
public:
	box(){
		cout << "����box����" << endl;
		height = width = 0;
	}
	int getheight() { return height; }
	int getwidth() { return width; }
	void setheight(int height) { this->height = height; }
	void setwidth(int width) { this->width = width; }
	~box(){ cout << "����box����" << endl; }
};
int main()
{
	box a;
	return 0;
}
