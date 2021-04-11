#include<iostream>
using namespace std;
int main()
{
	int myage = 39;
	int yourage = 39;
	cout << "i am: " << myage << " years old." << endl;
	cout << "you are: " << yourage << " years old." << endl;
	myage++;
	++yourage;
	cout << "one year passes..." << endl;
	cout << "i am: " << myage << " years old." << endl;
	cout << "you are: " << yourage << " years old." << endl;
	cout << "another year passes..." << endl;
	cout << "i am: " << myage++ << " years old." << endl;
	cout << "you are: " << ++yourage << " years old." << endl;
	cout << "let's print it again" << endl;
	cout << "i am: " << myage << " years old." << endl;
	cout << "you are: " << yourage << " years old." << endl;
	system("pause");
	return 0;
}