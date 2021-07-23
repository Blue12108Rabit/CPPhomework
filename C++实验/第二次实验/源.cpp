#include<iostream>
using namespace std;
class fract
{
public:
	void setnum(int n);
	void setden(int m);
	fract(int a, int b);
	void show();
	int getnum();//获取分子
	int getden();//获取分母
	int ged(int m, int n);//最大公约数
	int lcm(int m, int n);//最小公倍数
	fract add(fract f);
private:
	int num, den;
};
fract::fract(int a = 0, int b = 1)
{
	num = a;
	den = b;
}
void fract::show()
{
	cout << num << "/" << den << endl;
}
void fract::setnum(int n)
{
	num = n;
}
void fract::setden(int m)
{
	den = m;
}
int fract::getnum()
{
	return num;
}
int fract::getden()
{
	return den;
}
int fract::ged(int m, int n)
{
	int k;
	if (m < n)
		k = m;
	else
		k = n;
	while (0 != m % k || 0 != n % k)
	{
		k = k - 1;
	}
	return k;
}
int fract::lcm(int m, int n)
{
	int k;
	if (m < n)
		k = m;
	else
		k = n;
	while (0 != m % k || 0 != n % k)
	{
		k -= 1;
	}
	return (m * n) / k;
}
fract fract::add(fract f)
{
	int a;
	num = num * f.getden() + f.getnum() * den;
	den = den * f.getden();
	a = ged(den, num);
	setnum(num / a);
	setden(den / a);
	show();
	return f;
}
int main()
{
	fract f1(1, 5);
	f1.show();
	fract f2(7, 20);
	f2.show();
	f1.add(f2);
	system("pause");
	return 0;
}
