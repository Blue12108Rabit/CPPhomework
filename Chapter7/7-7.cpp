#include<iostream>
using namespace std;
class baseclass {
public:
	baseclass();
};
baseclass::baseclass() {
	cout << "����������" << endl;
}
class derivedclass :public baseclass{
public:
	derivedclass();
};
derivedclass::derivedclass() {
	cout << "�������������" << endl;
}

int main()
{
	derivedclass d;
	return 0;
}
