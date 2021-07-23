#include<iostream>
using namespace std;
class baseclass {
public:
	baseclass();
};
baseclass::baseclass() {
	cout << "构造基类对象！" << endl;
}
class derivedclass :public baseclass{
public:
	derivedclass();
};
derivedclass::derivedclass() {
	cout << "构造派生类对象！" << endl;
}

int main()
{
	derivedclass d;
	return 0;
}
