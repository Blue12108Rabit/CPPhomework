#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n = 3,s,m;
	cout << 2 << endl;
	cout << 3 << endl;
	while (n <= 100)
	{
		m = 2;
		s = sqrt(n);
		while (m <=s)
		{
			if (0 == n%m)
				break;
			else
				m += 1;
			if (m > s)
				cout << n << endl;
		}
		n += 2;
	}
	system("pause");
	return 0;
}
