#include<iostream>
using namespace std;
int main()
{
	cout << "Menu: A(dd) D(elete) S(ort) Q(uit),Select one:" << endl;
	char c;
	while (1)
	{
		cin >> c;
		if (c == 'a' || c == 'A')
		{
			cout << "The data has been added!" << endl;
			continue;
		}
		else if (c == 'd' || c == 'D')
		{
			cout << "The data has been deleted!" << endl;
			continue;
		}
		else if (c == 's' || c == 'S')
		{
			cout << "The data has been sorded!" << endl;
			continue;
		}
		else if (c == 'q' || c == 'Q')
			break;
		else
			cout << "Please input a correct command!" << endl;
	}
	system("pause");
	return 0;
}