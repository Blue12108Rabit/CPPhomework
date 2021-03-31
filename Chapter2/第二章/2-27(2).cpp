#include<iostream>
using namespace std;
int main()
{
	cout << "Menu: A(dd) D(elete) S(ort) Q(uit),Select one:" << endl;
	char c;
	while (1)
	{
		cin >> c;
		switch (c)
		{
		case'a':
		case'A':cout << "The data has been added!" << endl;
			break;
		case'd':
		case'D':cout << "The data has been deleted!" << endl;
			break;
		case's':
		case'S':cout << "The data has been sorted!" << endl;
			break;
		case'q':
		case'Q':system("pause"); 
			exit(0);
			break;
		default:
			cout << "Please input a correct command!" << endl;
		}

	}
	system("pause");
	return 0;
}