#include<iostream>
class ar {
private:
	int b[4][4];
public:
	ar(int* p[4]) {
		b[2][2] = p[2][2];
	}
};
int main() {
	int b[4][4][4];
	int* p[6];
	b[1][1][1] = p[1][1][1];
}