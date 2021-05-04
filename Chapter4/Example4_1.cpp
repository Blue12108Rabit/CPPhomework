#include<iostream>
using namespace std;
class clock1{
	public:
		clock1(int h, int m, int s);
		clock1();

		void settime(int newh = 0, int newm = 0, int news = 0);
		void showtime();
	private:
		int hour, minute, second;
};
clock1::clock1(int h,int m,int s):hour(h),minute(m),second(s)
{}
clock1::clock1() : hour(0), minute(0), second(0)
{}
void clock1::settime(int newh, int newm,int news)
{
	hour = newh;
	minute = newm;
	second = news;
}
inline void clock1::showtime()
{
	cout << hour << ":" << minute << ":" << second << endl;
}
int main()
{
	int a, b, c;
	clock1 myclock;
	cout << "first time set and output" << endl;
	myclock.settime();
	myclock.showtime();
	cout << "second time set and output:" << endl;
	cin >> a >> b >> c;
	myclock.settime(a,b,c);
	myclock.showtime();
	system("pause");
	return 0;
}