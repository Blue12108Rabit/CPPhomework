#include<iostream>
using namespace std;
class Array{
private:
	int b[4][4];
public:
	Array(int(*p)[4]);
	~Array() {};
	void operator++();
	friend void operator--(Array &b);
	void display();
};
Array::Array(int (*p)[4]){
	for (int c = 0; c < 4; c++)
	for (int d = 0; d < 4; d++)
		b[c][d] = p[c][d];
};

void Array::display(){
	for (int j = 0; j <= 3; j++){
		for (int i = 0; i <= 3; i++)
			cout << b[j][i]<<"," ;

	cout << endl;
	}
	cout << endl;
}
void Array::operator++(){
	int cache[4][4];
	for (int c = 0; c < 4; c++) 
	{
		for (int d = 0; d < 4; d++)
			cache[c][d] = b[c][d];
	}
	for (int c = 0; c < 4; c++) 
	{
		for (int d = 0; d < 4; d++)
			b[d][3 - c] = cache[c][d];
	}
}
void operator--(Array &b) {
	int cache[4][4];
	for (int c = 0; c < 4; c++) {
		for (int d = 0; d < 4; d++)
			cache[c][d] = b.b[c][d];
	}
	for (int c = 0; c < 4; c++) {
		for (int d = 0; d < 4; d++)
			b.b[3 - d][c] = cache[c][d];
	}
}
int main(){
	int a1[4][4] = {
		1,2,3,4,
		2,2,3,4,
		3,2,3,4,
		4,2,3,4
	};
	Array a(a1);
	a.operator++();
	a.display();
	Array b(a1);
	--b;
	b.display();
	system("pause");


}