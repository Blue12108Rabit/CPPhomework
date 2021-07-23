#include<iostream>
using namespace std;
int compare(int a, int b)
{
	if (a < b)
		cout << "a<b" << endl;
	else if (a>b)
		cout << "a>b" << endl;
	else
		cout << "a=b" << endl;
	return 0;

}
char compare(char a, char b)
{
	if (a < b)
		cout << "a<b" << endl;
	else if (a>b)
		cout << "a>b" << endl;
	else
		cout << "a=b" << endl;
	return 0;
}
class person
{
public:
	int age;
	void compare(int a, int b);
	void setAge();
};

void person::compare(int a, int b)
{
	if (a < b)
		cout << "a<b" << endl;
	else if (a>b)
		cout << "a>b" << endl;
	else
		cout << "a=b" << endl;
}
void person::setAge()
{
	int x;
	cout << "Person's age" << endl;
	cin >> x;
	age = x;
}

int main()
{
	int a, b;
	cout << "a= " ;
	cin >> a;
	cout << "b= ";
	cin >> b;

	compare(a,b);

	char x, y;
	cout << "a= ";
	cin >> x;
	cout << "b= ";
	cin >> y;

	compare(x, y);

	person personA;
	person personB;
	personA.setAge();
	personB.setAge();

	compare(personA.age, personB.age);

	system("pause");
	return 0;

}