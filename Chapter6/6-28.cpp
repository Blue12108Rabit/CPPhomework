#include<iostream>
using namespace std;
void splitFloat(float x, int &intPart,float &fracPart) {
	intPart = static_cast<int>(x);
	fracPart = x - intPart;
}
int main() {
	cout << "please input three numebers: " << endl;
	for (int i = 0; i < 3; i++) {
		float x, f;
		int n;
		cin >> x;
		splitFloat(x, n, f);
		cout << n << "+" << f << endl;
	}
	return 0;
}