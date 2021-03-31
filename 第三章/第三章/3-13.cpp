#include<iostream>
#include<cmath>
using namespace std;
int fun(int n)
{
	int sum;
	if (2 == n||1==n)
		sum=1;
	else
		sum = fun(n - 1) + fun(n - 2);
	return sum;
}
int main()
{
	int n;
	cin >> n;
	if (n <= 2)
		cout << "n >2!" << endl;
	else
		cout << fun(n) << endl;
	system("pause");
}