#include<iostream>
using namespace std;
int main()
{
	int a, mod, i=1,k=1;
	cout << "a = ";
	cin >> a;
	cout << "mod = ";
	cin >> mod;
	if (a * k != (mod * i + 1))
	{
		while (k != mod)
		{
			k++;
			if (a * k != (mod * i + 1))
			{
				if (mod * i <= a * k)
				{
					i++;
				}
			}
			else
				cout << k << endl;
		}
	}
	else
		cout << k << endl;
	system("pause");
	return 0;
	
}